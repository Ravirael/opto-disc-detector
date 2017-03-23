#include "CannyEdgeDetectionStage.h"
#include <opencv2/imgproc.hpp>

namespace {
    void autoBrightnessContrast(const cv::Mat &src, cv::Mat &dst, float clipHistPercent)
    {
        assert(clipHistPercent >= 0);
        assert(src.type() == CV_8UC1);

        const int MAX_VALUE = 256;
        double min = 0, max = MAX_VALUE - 1;

        cv::Mat gray = src;
        if (clipHistPercent == 0) {
            cv::minMaxLoc(gray, &min, &max);
        } else {
            cv::Mat hist;

            std::vector<float> range = { 0, MAX_VALUE };
            const float *rangeData = range.data();
            cv::calcHist(&gray, 1, 0, cv::Mat(), hist, 1, &MAX_VALUE, &rangeData);

            std::vector<float> accumulator(MAX_VALUE);
            accumulator[0] = hist.at<float>(0);
            for (std::size_t i = 1; i < MAX_VALUE; i++) {
                accumulator[i] = accumulator[i - 1] + hist.at<float>(i);
            }


            double lowThreshold = (clipHistPercent * (accumulator.back() / 100.f)) / 2.f;
            double highThreshold = accumulator.back() - lowThreshold;

            while (accumulator[min] < lowThreshold) {
                min++;
            }

            while (accumulator[max] >= highThreshold) {
                max--;
            }
        }

        double inputRange = max - min;
        double alpha = (MAX_VALUE - 1) / inputRange;
        double beta = -min * alpha;

        src.convertTo(dst, -1, alpha, beta);
    }
}

cv::Mat CannyEdgeDetectionStage::operator()(cv::Mat img) const {
    cv::Mat mat = img.clone();
    cv::GaussianBlur(mat, mat, {5, 5}, 1.25f);

    autoBrightnessContrast(mat, mat, 0.f);

    //cv::Canny(mat, mat, 6, 24);
    cv::adaptiveThreshold(mat, mat, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 21, 3);
    return mat;
}


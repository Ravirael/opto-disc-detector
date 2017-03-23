#include <opencv2/imgproc.hpp>
#include "ThresholdingStage.h"

cv::Mat ThresholdingStage::operator()(cv::Mat input) const {
    constexpr int normalizationColorSpace = 16;

    cv::Mat output;
    cv::normalize(input, output, normalizationColorSpace, 0, cv::NORM_MINMAX); //reduce to n colors
    cv::threshold(output, output, normalizationColorSpace * 0.80, 255, CV_THRESH_BINARY); //remove all but brightest
//    return output;
    //cv::adaptiveThreshold(output, output, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 71, 1);
    return output;
}

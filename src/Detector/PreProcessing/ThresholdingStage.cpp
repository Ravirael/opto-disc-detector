#include <opencv2/imgproc.hpp>
#include "ThresholdingStage.h"

cv::Mat ThresholdingStage::operator()(cv::Mat input) const {
    constexpr int normalizationColorSpace = 16;

    cv::Mat output;
    //cv::normalize(input, output, normalizationColorSpace, 0, cv::NORM_MINMAX); //reduce to n colors
    //cv::threshold(output, output, normalizationColorSpace * 0.90, 255, CV_THRESH_BINARY); //remove all but brightest
//    return output;
    cv::adaptiveThreshold(input, output, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 91, 1);
    return output;
}

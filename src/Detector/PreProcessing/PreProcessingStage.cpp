#include "PreProcessingStage.h"
#include <opencv2/imgproc.hpp>

cv::Mat PreProcessingStage::operator()(cv::Mat input) const {
    const int imageColorSpace = 2;
    if (input.type() == CV_8UC3) {
        std::vector<cv::Mat> channels;
        cv::split(input, channels);
        cv::Mat output = channels[1]; //BGR order
        cv::normalize(output, output, imageColorSpace, 0, cv::NORM_MINMAX); //to 8-color-space
        //cv::normalize(output, output, 255, 0, cv::NORM_MINMAX); //back to standard grayscale range
        cv::threshold(output, output, imageColorSpace - 1, 255, CV_THRESH_BINARY);
        cv::dilate(output, output, cv::getStructuringElement(CV_SHAPE_ELLIPSE, cv::Size(7, 7)));
        return output;
    }

    throw std::runtime_error("Unknown image type!");
}

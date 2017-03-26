#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "ToGrayscale.h"

cv::Mat ToGrayscale::operator()(cv::Mat input) const {
    if (input.type() == CV_8UC3) {
        cv::Mat output;
        std::vector<cv::Mat> channels;
        cv::split(input, channels);
        cv::cvtColor(input, output, CV_BGR2GRAY);
        return output;
        return channels[1]; //green channel - contains most information
    } else if (input.type() == CV_8UC1) {
        return input;
    }
    throw std::invalid_argument("In ToGrayscale expected BGR or grayscale image as input!");
}

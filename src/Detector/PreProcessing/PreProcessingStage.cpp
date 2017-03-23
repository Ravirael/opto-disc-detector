#include "PreProcessingStage.h"
#include <opencv2/imgproc.hpp>

cv::Mat PreProcessingStage::operator()(cv::Mat input) const {
    cv::Mat output;

    if (input.type() != CV_8UC1) {
        cv::cvtColor(input, output, CV_BGR2GRAY);
    } else {
        output = input.clone();
    }

    return output;
}

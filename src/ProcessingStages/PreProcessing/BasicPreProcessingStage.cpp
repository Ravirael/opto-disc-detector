#include "BasicPreProcessingStage.h"
#include <opencv2/imgproc.hpp>

cv::Mat BasicPreProcessingStage::operator()(cv::Mat input) const {
    cv::Mat output;

    if (input.type() != CV_8UC1) {
        cv::cvtColor(input, output, CV_BGR2GRAY);
        mProgressSignal("Grayscale image", output);
    } else {
        output = input.clone();
    }

    return output;
}

boost::signals2::connection BasicPreProcessingStage::connect(std::function<void(std::string, const cv::Mat)> slot) {
    return mProgressSignal.connect(std::move(slot));
}

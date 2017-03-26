#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "HistogramEqualization.h"

cv::Mat HistogramEqualization::operator()(cv::Mat input) const {
    std::vector<cv::Mat> channels;
    cv::split(input, channels);

    for (auto &channel : channels) {
        cv::equalizeHist(channel, channel);
    }

    cv::Mat output;
    cv::merge(channels, output);
    return output;
}

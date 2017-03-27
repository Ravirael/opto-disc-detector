#include <opencv2/imgproc.hpp>
#include "GlobalThreshold.h"

GlobalThreshold::GlobalThreshold(const unsigned int threshold) :
        mThreshold(threshold) {

}

cv::Mat GlobalThreshold::operator()(cv::Mat input) const {
    cv::Mat output;
    cv::threshold(input, output, mThreshold, 255, CV_THRESH_BINARY);
    return output;
}

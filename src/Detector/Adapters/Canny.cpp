#include "Canny.h"
#include <opencv2/imgproc.hpp>

Canny::Canny(const unsigned int lowerThreshold, const unsigned int upperThreshold) noexcept:
        mLowerThreshold(lowerThreshold),
        mUpperThreshold(upperThreshold) {

}

cv::Mat Canny::operator()(cv::Mat input) const {
    cv::Mat output;
    cv::Canny(input, output, mLowerThreshold, mUpperThreshold);
    return output;
}

#include "MinMaxNormalize.h"

#include <opencv2/imgproc.hpp>

MinMaxNormalize::MinMaxNormalize(const unsigned numberOfColors, const unsigned maxValue) noexcept
        : mNumberOfColors(numberOfColors),
          mMaxValue(maxValue) {

}

cv::Mat MinMaxNormalize::operator()(cv::Mat input) const {
    cv::Mat output;
    cv::normalize(input, output, mNumberOfColors, 0, cv::NORM_MINMAX); //reduce to 0 - n range
    cv::normalize(output, output, mMaxValue, 0, cv::NORM_MINMAX); //back to 0 - maxValue range
    return output;
}

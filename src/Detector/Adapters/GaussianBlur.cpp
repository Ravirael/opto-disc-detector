#include <opencv2/imgproc.hpp>
#include "GaussianBlur.h"

GaussianBlur::GaussianBlur(const double size, const double sigma) noexcept:
        mSize(size),
        mSigma(sigma) {

}

cv::Mat GaussianBlur::operator()(cv::Mat input) const {
    const int size = mSize * input.cols;
    cv::Mat output;
    cv::GaussianBlur(input, output, cv::Size(size, size), mSigma);
    return output;
}

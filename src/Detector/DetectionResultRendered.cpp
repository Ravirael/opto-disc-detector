#include <opencv2/imgproc.hpp>
#include "DetectionResultRendered.h"

DetectionResultRendered::DetectionResultRendered(OpticDiscDetectionResult *result) :
    mResult(result) {

}

cv::Mat DetectionResultRendered::operator()(cv::Mat image) const {
    const auto circles = mResult->all();
    for(const auto &circle : circles)
    {
        const cv::Point center(circle.center().x(), circle.center().y());
        const int radius = circle.radius();
        // circle center
        cv::circle(image, center, 2, cv::Scalar(0, 255, 0), -1, 8, 0 );
        // circle outline
        cv::circle(image, center, radius, cv::Scalar(255, 0, 0), 1, 8, 0 );
    }

    if (mResult->best()) {
        auto circle = mResult->best().get();
        const cv::Point center(circle.center().x(), circle.center().y());
        const int radius = circle.radius();
        cv::circle(image, center, radius, cv::Scalar(255, 255, 0), 1, 8, 0);
    }

    return image;
}

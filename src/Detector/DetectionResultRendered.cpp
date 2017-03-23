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
        cv::circle( image, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
        // circle outline
        cv::circle( image, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
    }
    return image;
}

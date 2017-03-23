#include <opencv2/imgproc.hpp>
#include "HoughTransformStage.h"

std::vector<cv::Vec3f> HoughTransformStage::operator()(cv::Mat input) const {
    const double minDistance = 2;
    const double accumulatorResolutionRatio = 1;
    const double cannyThreshold = 100;
    const double accumulatorThreshold = 10;
    const double minRadius = 0.05/2 * input.cols;
    const double maxRadius = 0.25/2 * input.cols;

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(input,
                     circles,
                     CV_HOUGH_GRADIENT,
                     accumulatorResolutionRatio,
                     minDistance,
                     cannyThreshold,
                     accumulatorThreshold,
                     minRadius,
                     maxRadius);
    return circles;
}

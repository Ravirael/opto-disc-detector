#include <opencv2/imgproc.hpp>
#include "HoughTransformStage.h"

std::vector<cv::Vec3f> HoughTransformStage::operator()(cv::Mat input) const {
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(input, circles, CV_HOUGH_GRADIENT, 1, input.rows/8, 200, 100, 0, 0);
    return circles;
}

#include <opencv2/imgproc.hpp>
#include "MorphologicalStage.h"

cv::Mat MorphologicalStage::operator()(cv::Mat input) const {
    const int size = 2*((input.cols/100)/2) + 1;
    cv::Mat output;
    cv::morphologyEx(input, output, CV_MOP_CLOSE, cv::getStructuringElement(CV_SHAPE_ELLIPSE, cv::Size(size, size)));
    cv::dilate(output, output, cv::getStructuringElement(CV_SHAPE_ELLIPSE, cv::Size(size, size)));
    return output;
}

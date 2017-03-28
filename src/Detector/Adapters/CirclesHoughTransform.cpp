#include <opencv2/imgproc.hpp>
#include "CirclesHoughTransform.h"
#include "../HoughTransform/HoughParameters.h"

CirclesHoughTransform::CirclesHoughTransform(std::unique_ptr<HoughParameters> &&parameters) :
        mParameters(std::move(parameters)) {

}

std::vector<cv::Vec3f> CirclesHoughTransform::operator()(cv::Mat input) const {
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(
            input,
            circles,
            CV_HOUGH_GRADIENT,
            mParameters->accumulatorResolutionRatio(input),
            mParameters->minDistance(input),
            mParameters->upperCannyThreshold(input),
            mParameters->accumulatorThreshold(input),
            mParameters->minRadius(input),
            mParameters->maxRadius(input)
    );
    return circles;
}

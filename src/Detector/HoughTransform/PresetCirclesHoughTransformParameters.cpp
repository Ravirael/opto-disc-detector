#include "PresetCirclesHoughTransformParameters.h"

PresetCirclesHoughTransformParameters::PresetCirclesHoughTransformParameters() {

}

double PresetCirclesHoughTransformParameters::accumulatorResolutionRatio(const cv::Mat &) const {
    return mAccumlatorResolutionRatio;
}

double PresetCirclesHoughTransformParameters::minDistance(const cv::Mat &input) const {
    return mMinDistance * input.cols;
}

double PresetCirclesHoughTransformParameters::upperCannyThreshold(const cv::Mat &) const {
    return mUpperCannyThreshold;
}

double PresetCirclesHoughTransformParameters::minRadius(const cv::Mat &input) const {
    return mMinRadius * input.cols;
}

double PresetCirclesHoughTransformParameters::maxRadius(const cv::Mat &input) const {
    return mMaxRadius * input.cols;
}

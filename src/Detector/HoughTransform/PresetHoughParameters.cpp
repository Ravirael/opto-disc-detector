#include "PresetHoughParameters.h"

//Well... Use PresetHoughParametersFactory instead...
PresetHoughParameters::PresetHoughParameters(const double minRadius,
                                                                             const double maxRadius,
                                                                             const double minDistance,
                                                                             const double upperCannyThreshold,
                                                                             const unsigned int accumulatorThreshold,
                                                                             const double accumulatorResolutionRatio)
        : mMinRadius(minRadius),
          mMaxRadius(maxRadius),
          mMinDistance(minDistance),
          mUpperCannyThreshold(upperCannyThreshold),
          mAccumulatorThreshold(accumulatorThreshold),
          mAccumulatorResolutionRatio(accumulatorResolutionRatio) {

}

double PresetHoughParameters::accumulatorResolutionRatio(const cv::Mat &) const {
    return mAccumulatorResolutionRatio;
}

double PresetHoughParameters::minDistance(const cv::Mat &input) const {
    return mMinDistance * input.cols;
}

double PresetHoughParameters::upperCannyThreshold(const cv::Mat &) const {
    return mUpperCannyThreshold;
}

double PresetHoughParameters::minRadius(const cv::Mat &input) const {
    return mMinRadius * input.cols;
}

double PresetHoughParameters::maxRadius(const cv::Mat &input) const {
    return mMaxRadius * input.cols;
}

unsigned int PresetHoughParameters::accumulatorThreshold(const cv::Mat &) const {
    return mAccumulatorThreshold;
}



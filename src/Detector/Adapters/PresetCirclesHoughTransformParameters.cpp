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

PresetCirclesHoughTransformParametersBuilder::PresetCirclesHoughTransformParametersBuilder() :
    mParameters(new PresetCirclesHoughTransformParameters()) {

}

PresetCirclesHoughTransformParametersBuilder &
PresetCirclesHoughTransformParametersBuilder::setAccumulatorResolutionRatio(double ratio) {
    mParameters->mAccumlatorResolutionRatio = ratio;
    return *this;
}

PresetCirclesHoughTransformParametersBuilder &
PresetCirclesHoughTransformParametersBuilder::setAccumulatorThreshold(unsigned threshold) {
    mParameters->mAccumulatorThreshold = threshold;
    return *this;
}

unsigned int PresetCirclesHoughTransformParameters::accumulatorThreshold(const cv::Mat &) const {
    return mAccumulatorThreshold;
}

PresetCirclesHoughTransformParametersBuilder &PresetCirclesHoughTransformParametersBuilder::setRelativeMinDistance(double minDistance) {
    mParameters->mMinDistance = minDistance;
    return *this;
}

PresetCirclesHoughTransformParametersBuilder &PresetCirclesHoughTransformParametersBuilder::setUpperCannyThreshold(double threshold) {
    mParameters->mUpperCannyThreshold = threshold;
    return *this;
}

PresetCirclesHoughTransformParametersBuilder &PresetCirclesHoughTransformParametersBuilder::setRelativeMinRadius(double minRadius) {
    mParameters->mMinRadius = minRadius;
    return *this;
}

PresetCirclesHoughTransformParametersBuilder &PresetCirclesHoughTransformParametersBuilder::setRelativeMaxRadius(double maxRadius) {
    mParameters->mMaxRadius = maxRadius;
    return *this;
}

std::unique_ptr<PresetCirclesHoughTransformParameters> PresetCirclesHoughTransformParametersBuilder::build() {
    auto toReturn = std::move(mParameters);
    mParameters.reset(new PresetCirclesHoughTransformParameters());
    return toReturn;
}

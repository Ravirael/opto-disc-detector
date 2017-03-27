#include "PresetCirclesHoughTransformParametersBuilder.h"
#include "PresetCirclesHoughTransformParameters.h"

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

std::unique_ptr<CirclesHoughTransformParameters> PresetCirclesHoughTransformParametersBuilder::build() {
    auto toReturn = std::move(mParameters);
    mParameters.reset(new PresetCirclesHoughTransformParameters());
    return toReturn;
}
#include "PresetHoughParametersFactory.h"
#include "PresetHoughParameters.h"


PresetHoughParametersFactory::PresetHoughParametersFactory() {

}

PresetHoughParametersFactory &
PresetHoughParametersFactory::setAccumulatorResolutionRatio(double ratio) {
    mAccumulatorResolutionRatio = ratio;
    return *this;
}

PresetHoughParametersFactory &
PresetHoughParametersFactory::setAccumulatorThreshold(unsigned threshold) {
    mAccumulatorThreshold = threshold;
    return *this;
}

PresetHoughParametersFactory &PresetHoughParametersFactory::setRelativeMinDistance(double minDistance) {
    mMinDistance = minDistance;
    return *this;
}

PresetHoughParametersFactory &PresetHoughParametersFactory::setUpperCannyThreshold(double threshold) {
    mUpperCannyThreshold = threshold;
    return *this;
}

PresetHoughParametersFactory &PresetHoughParametersFactory::setRelativeMinRadius(double minRadius) {
    mMinRadius = minRadius;
    return *this;
}

PresetHoughParametersFactory &PresetHoughParametersFactory::setRelativeMaxRadius(double maxRadius) {
    mMaxRadius = maxRadius;
    return *this;
}

std::unique_ptr<HoughParameters> PresetHoughParametersFactory::create() const {
    return std::make_unique<PresetHoughParameters>(
            mMinRadius,
            mMaxRadius,
            mMinDistance,
            mUpperCannyThreshold,
            mAccumulatorThreshold,
            mAccumulatorResolutionRatio
    );
}
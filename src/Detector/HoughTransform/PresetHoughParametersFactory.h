#pragma once
#include <memory>
#include "HoughParametersFactory.h"

class PresetHoughParametersFactory final : public HoughParametersFactory {
    double mMinRadius = 0.0;
    double mMaxRadius = 1.0;
    double mMinDistance = 0.02;
    double mUpperCannyThreshold = 200;
    unsigned mAccumulatorThreshold = 10;
    double mAccumulatorResolutionRatio = 1.0;

public:
    PresetHoughParametersFactory();
    PresetHoughParametersFactory &setAccumulatorResolutionRatio(double ratio);
    PresetHoughParametersFactory &setRelativeMinDistance(double minDistance);
    PresetHoughParametersFactory &setUpperCannyThreshold(double threshold);
    PresetHoughParametersFactory &setRelativeMinRadius(double minRadius);
    PresetHoughParametersFactory &setRelativeMaxRadius(double maxRadius);
    PresetHoughParametersFactory &setAccumulatorThreshold(unsigned threshold);
    std::unique_ptr<HoughParameters> create() const override;
};
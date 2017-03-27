#pragma once
#include <memory>
#include "CirclesHoughTransformParametersBuilder.h"
#include "PresetCirclesHoughTransformParameters.h"

class PresetCirclesHoughTransformParameters;

class PresetCirclesHoughTransformParametersBuilder final : public CirclesHoughTransformParametersBuilder {
    std::unique_ptr<PresetCirclesHoughTransformParameters> mParameters;

public:
    PresetCirclesHoughTransformParametersBuilder();
    PresetCirclesHoughTransformParametersBuilder &setAccumulatorResolutionRatio(double ratio);
    PresetCirclesHoughTransformParametersBuilder &setRelativeMinDistance(double minDistance);
    PresetCirclesHoughTransformParametersBuilder &setUpperCannyThreshold(double threshold);
    PresetCirclesHoughTransformParametersBuilder &setRelativeMinRadius(double minRadius);
    PresetCirclesHoughTransformParametersBuilder &setRelativeMaxRadius(double maxRadius);
    PresetCirclesHoughTransformParametersBuilder &setAccumulatorThreshold(unsigned threshold);
    std::unique_ptr<CirclesHoughTransformParameters> build() override;
};
#pragma once


#include <memory>
#include "CirclesHoughTransformParameters.h"

class PresetCirclesHoughTransformParameters;

class PresetCirclesHoughTransformParametersBuilder final {
    std::unique_ptr<PresetCirclesHoughTransformParameters> mParameters;

public:
    PresetCirclesHoughTransformParametersBuilder();
    PresetCirclesHoughTransformParametersBuilder &setAccumulatorResolutionRatio(double ratio);
    PresetCirclesHoughTransformParametersBuilder &setRelativeMinDistance(double minDistance);
    PresetCirclesHoughTransformParametersBuilder &setUpperCannyThreshold(double threshold);
    PresetCirclesHoughTransformParametersBuilder &setRelativeMinRadius(double minRadius);
    PresetCirclesHoughTransformParametersBuilder &setRelativeMaxRadius(double maxRadius);
    PresetCirclesHoughTransformParametersBuilder &setAccumulatorThreshold(unsigned threshold);
    std::unique_ptr<PresetCirclesHoughTransformParameters> build();
};

class PresetCirclesHoughTransformParameters final: public CirclesHoughTransformParameters {
    friend class PresetCirclesHoughTransformParametersBuilder;

    double mAccumlatorResolutionRatio = 1.0;
    double mMinDistance = 0.02;
    double mUpperCannyThreshold = 200;
    double mMinRadius = 0.0;
    double mMaxRadius = 1.0;
    unsigned mAccumulatorThreshold = 10;

    PresetCirclesHoughTransformParameters();
public:
    double accumulatorResolutionRatio(const cv::Mat &input) const override;
    double minDistance(const cv::Mat &input) const override;
    double upperCannyThreshold(const cv::Mat &input) const override;
    unsigned int accumulatorThreshold(const cv::Mat &input) const override;
    double minRadius(const cv::Mat &input) const override;
    double maxRadius(const cv::Mat &input) const override;
};



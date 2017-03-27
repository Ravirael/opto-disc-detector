#pragma once

#include <memory>
#include "CirclesHoughTransformParameters.h"

class PresetCirclesHoughTransformParametersBuilder;

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



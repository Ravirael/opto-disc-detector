#pragma once

#include <memory>
#include "HoughParameters.h"

class PresetHoughParameters final: public HoughParameters {

    const double mMinRadius = 0.0;
    const double mMaxRadius = 1.0;
    const double mMinDistance = 0.02;
    const double mUpperCannyThreshold = 200;
    const unsigned mAccumulatorThreshold = 10;
    const double mAccumulatorResolutionRatio = 1.0;

public:
    //Well... Use PresetHoughParametersFactory instead...
    PresetHoughParameters(const double minRadius, const double maxRadius, const double minDistance,
                                          const double upperCannyThreshold, const unsigned int accumulatorThreshold,
                                          const double accumulatorResolutionRatio);
    double accumulatorResolutionRatio(const cv::Mat &input) const override;
    double minDistance(const cv::Mat &input) const override;
    double upperCannyThreshold(const cv::Mat &input) const override;
    unsigned int accumulatorThreshold(const cv::Mat &input) const override;
    double minRadius(const cv::Mat &input) const override;
    double maxRadius(const cv::Mat &input) const override;
};



#pragma once


#include <json.hpp>
#include "CirclesHoughTransformParameters.h"
#include "PresetCirclesHoughTransformParameters.h"

class JsonHoughTransformParameters final: CirclesHoughTransformParameters {
    std::unique_ptr<CirclesHoughTransformParameters> mParameters;
public:
    JsonHoughTransformParameters(const nlohmann::json &json);
    double accumulatorResolutionRatio(const cv::Mat &input) const override;
    double minDistance(const cv::Mat &input) const override;
    double upperCannyThreshold(const cv::Mat &input) const override;
    double minRadius(const cv::Mat &input) const override;
    double maxRadius(const cv::Mat &input) const override;
    unsigned int accumulatorThreshold(const cv::Mat &input) const override;
};



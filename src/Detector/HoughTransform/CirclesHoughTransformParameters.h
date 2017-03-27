#pragma once

#include <opencv2/core/mat.hpp>

class CirclesHoughTransformParameters {
public:
    virtual double accumulatorResolutionRatio(const cv::Mat &input) const = 0;
    virtual double minDistance(const cv::Mat &input) const = 0;
    virtual double upperCannyThreshold(const cv::Mat &input) const = 0;
    virtual double minRadius(const cv::Mat &input) const = 0;
    virtual double maxRadius(const cv::Mat &input) const = 0;
    virtual unsigned accumulatorThreshold(const cv::Mat &input) const = 0;
    virtual ~CirclesHoughTransformParameters() noexcept;
};



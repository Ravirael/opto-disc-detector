#pragma once

#include <memory>
#include <opencv2/core/mat.hpp>
#include "../ProcessingStage.h"

class CirclesHoughTransformParameters;

class CirclesHoughTransform final: public ProcessingStage<cv::Mat, std::vector<cv::Vec3f>> {
    const std::unique_ptr<const CirclesHoughTransformParameters> mParameters;
public:
    CirclesHoughTransform(std::unique_ptr<CirclesHoughTransformParameters> &&parameters);
    std::vector<cv::Vec3f> operator()(cv::Mat input) const override;
};



#pragma once

#include <memory>
#include <opencv2/core/mat.hpp>
#include "../ProcessingStage.h"

class HoughParameters;

class CirclesHoughTransform final: public ProcessingStage<cv::Mat, std::vector<cv::Vec3f>> {
    const std::unique_ptr<const HoughParameters> mParameters;
public:
    CirclesHoughTransform(std::unique_ptr<HoughParameters> &&parameters);
    std::vector<cv::Vec3f> operator()(cv::Mat input) const override;
};



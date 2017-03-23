#pragma once


#include <opencv2/core/mat.hpp>
#include "../ProcessingStage.h"

class HoughTransformStage final: public ProcessingStage<cv::Mat, std::vector<cv::Vec3f>> {
public:
    Result operator()(Argument arg) const override;
};



#pragma once


#include "../ImageProcessingStage.h"

class ToGrayscaleStage final : public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat arg) const override;
};



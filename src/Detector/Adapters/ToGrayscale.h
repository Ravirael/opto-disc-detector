#pragma once


#include "../ImageProcessingStage.h"

class ToGrayscale final : public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat arg) const override;
};



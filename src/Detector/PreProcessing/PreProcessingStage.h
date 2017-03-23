#pragma once
#include "../ImageProcessingStage.h"

class PreProcessingStage final: public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat inputImage) const override;
};



#pragma once
#include "../ImageProcessingStage.h"

class BasicPreProcessingStage : public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat inputImage) const override;
};



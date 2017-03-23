#pragma once
#include "../ImageProcessingStage.h"

class BasicPreProcessingStage final: public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat inputImage) const override;
};



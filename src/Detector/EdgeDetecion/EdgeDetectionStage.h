#pragma once

#include "../ImageProcessingStage.h"

class EdgeDetectionStage final: public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat inputImage) const override;
};



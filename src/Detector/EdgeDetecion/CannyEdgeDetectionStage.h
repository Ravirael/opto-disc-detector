#pragma once

#include "../ImageProcessingStage.h"

class CannyEdgeDetectionStage : public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat inputImage) const override;
};



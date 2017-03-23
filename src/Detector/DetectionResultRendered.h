#pragma once


#include "ImageProcessingStage.h"
#include "OpticDiscDetectionResult.h"

class DetectionResultRendered final: public ImageProcessingStage {
    const OpticDiscDetectionResult *mResult;
public:
    DetectionResultRendered(OpticDiscDetectionResult *result);
    cv::Mat operator()(cv::Mat mat) const override;
};



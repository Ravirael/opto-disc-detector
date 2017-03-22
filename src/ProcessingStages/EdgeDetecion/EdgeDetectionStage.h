#pragma once


#include <opencv2/core/mat.hpp>
#include "../ProcessingSubstepNotificator.h"

class EdgeDetectionStage : public ProcessingSubstepNotificator {
public:
    virtual cv::Mat operator()(cv::Mat inputImage) const = 0;
    virtual ~EdgeDetectionStage() noexcept;
};



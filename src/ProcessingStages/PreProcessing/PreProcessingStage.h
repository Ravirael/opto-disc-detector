#pragma once
#include <opencv2/core.hpp>
#include "../ProcessingSubstepNotificator.h"

class PreProcessingStage : public ProcessingSubstepNotificator {
public:
    virtual cv::Mat operator()(cv::Mat inputImage) const = 0;
    virtual ~PreProcessingStage() noexcept;
};



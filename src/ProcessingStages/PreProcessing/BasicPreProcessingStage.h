#pragma once
#include "PreProcessingStage.h"

class BasicPreProcessingStage : public PreProcessingStage {
    ProcessingSubstepNotificator::Signal mProgressSignal;

public:
    cv::Mat operator()(cv::Mat inputImage) const override;
    boost::signals2::connection connect(std::function<void(std::string, const cv::Mat)> slot) override;
};



#pragma once


#include "EdgeDetectionStage.h"

class CannyEdgeDetectionStage : public EdgeDetectionStage {
    ProcessingSubstepNotificator::Signal mProgressSignal;

public:
    cv::Mat operator()(cv::Mat inputImage) const override;
    boost::signals2::connection connect(std::function<SlotSignature> slot) override;
};



#pragma once


#include <opencv2/core/mat.hpp>
#include <mutex>
#include "ProcessingStageDecorator.h"

class DisplayingDecorator final: public ProcessingStageDecorator<cv::Mat> {
    const std::string mWindowName{"Window"};
public:
    using ProcessingStageDecorator<cv::Mat>::ProcessingStageDecorator;
    cv::Mat operator()(cv::Mat arg) const override;

};



#pragma once


#include <opencv2/core/mat.hpp>
#include <mutex>
#include "ProcessingStageDecorator.h"
#include "CvNamedWindow.h"

class DisplayingDecorator final: public ProcessingStageDecorator<cv::Mat> {
    static std::unique_ptr<CvNamedWindow> mWindow;
public:
    using ProcessingStageDecorator<cv::Mat>::ProcessingStageDecorator;
    cv::Mat operator()(cv::Mat arg) const override;
};



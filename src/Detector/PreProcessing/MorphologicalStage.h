#pragma once


#include "../ImageProcessingStage.h"

class MorphologicalStage final: public ImageProcessingStage {
public:
    cv::Mat operator()(cv::Mat arg) const override;
};



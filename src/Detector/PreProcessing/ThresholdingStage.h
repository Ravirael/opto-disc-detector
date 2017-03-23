#pragma once


#include "../ImageProcessingStage.h"

class ThresholdingStage final: public ImageProcessingStage {
public:
    Result operator()(Argument arg) const override;
};



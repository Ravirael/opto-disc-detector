#pragma once


#include "../ImageProcessingStage.h"

class GlobalThreshold final: public ImageProcessingStage {
    const unsigned mThreshold;
public:
    GlobalThreshold(const unsigned int threshold);
    Result operator()(Argument arg) const override;
};



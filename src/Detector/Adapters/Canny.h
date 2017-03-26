#pragma once


#include "../ImageProcessingStage.h"

class Canny final: public ImageProcessingStage {
    const unsigned mLowerThreshold;
    const unsigned mUpperThreshold;
public:
    Canny(const unsigned int lowerThreshold, const unsigned int upperThreshold) noexcept;
    Result operator()(Argument arg) const override;

};



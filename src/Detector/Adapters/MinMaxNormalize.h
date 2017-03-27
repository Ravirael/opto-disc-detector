#pragma once


#include "../ImageProcessingStage.h"

class MinMaxNormalize final: public ImageProcessingStage {
    const unsigned mNumberOfColors;
    const unsigned mMaxValue;
public:
    MinMaxNormalize(const unsigned numberOfColors, const unsigned maxValue = 255) noexcept;
    Result operator()(Argument arg) const override;

};



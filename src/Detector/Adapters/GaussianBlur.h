#pragma once


#include "../ImageProcessingStage.h"

class GaussianBlur final: public ImageProcessingStage {
    const double mSize;
    const double mSigma;

public:
    GaussianBlur(const double size, const double sigma) noexcept;
    Result operator()(Argument arg) const override;
};



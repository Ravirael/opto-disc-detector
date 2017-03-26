#pragma once


#include "../ImageProcessingStage.h"

class HistogramEqualization final : public ImageProcessingStage {
public:
    Result operator()(Argument arg) const override;
};



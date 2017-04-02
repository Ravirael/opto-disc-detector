#pragma once


#include "ImageProcessingStage.h"

class TrimBorder final: public ImageProcessingStage {
public:
    Result operator()(Argument arg) const override;
};



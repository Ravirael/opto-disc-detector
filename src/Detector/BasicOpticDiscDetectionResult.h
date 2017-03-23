#pragma once


#include "OpticDiscDetectionResult.h"

class BasicOpticDiscDetectionResult final: public OpticDiscDetectionResult {
    const std::vector<Circle<int>> mCircles;
public:
    BasicOpticDiscDetectionResult(std::vector<Circle<int>> circles);
    std::vector<Circle<int>> all() const override;
    Circle<int> best() const override;

};



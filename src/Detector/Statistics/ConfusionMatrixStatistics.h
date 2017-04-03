#pragma once


#include <memory>
#include <json.hpp>
#include "ConfusionMatrix.h"

class ConfusionMatrixStatistics {
    std::unique_ptr<ConfusionMatrix> mConfusionMatrix;
public:
    ConfusionMatrixStatistics(std::unique_ptr<ConfusionMatrix> confusionMatrix);
    unsigned truePositive() const;
    unsigned trueNegative() const;
    unsigned falsePositive() const;
    unsigned falseNegative() const;
    unsigned positive() const;
    unsigned negative() const;
    double sensitivity() const;
    double specificity() const;
    double accuracy() const;
};

void to_json(nlohmann::json& j, const ConfusionMatrixStatistics& statistics);



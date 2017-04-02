#include "ConfusionMatrixStatistics.h"

ConfusionMatrixStatistics::ConfusionMatrixStatistics(std::unique_ptr<ConfusionMatrix> confusionMatrix)
        : mConfusionMatrix(std::move(confusionMatrix)) {

}

unsigned ConfusionMatrixStatistics::truePositive() const {
    return mConfusionMatrix->truePositive();
}

unsigned ConfusionMatrixStatistics::trueNegative() const {
    return mConfusionMatrix->trueNegative();
}

unsigned ConfusionMatrixStatistics::falsePositive() const {
    return mConfusionMatrix->falsePositive();
}

unsigned ConfusionMatrixStatistics::falseNegative() const {
    return mConfusionMatrix->falseNegative();
}

unsigned ConfusionMatrixStatistics::positive() const {
    return truePositive() + falseNegative();
}

unsigned ConfusionMatrixStatistics::negative() const {
    return trueNegative() + falsePositive();
}

double ConfusionMatrixStatistics::sensitivity() const {
    return static_cast<double>(truePositive())/positive();
}

double ConfusionMatrixStatistics::specificity() const {
    return static_cast<double>(trueNegative())/negative();
}

double ConfusionMatrixStatistics::accuracy() const {
    return static_cast<double>(truePositive() + trueNegative())/(truePositive() + falsePositive() + trueNegative() + falseNegative());
}

void to_json(nlohmann::json &j, const ConfusionMatrixStatistics &statistics) {
    j = nlohmann::json{
            {"positive", statistics.positive()},
            {"negative", statistics.negative()},
            {"truePositive", statistics.truePositive()},
            {"falsePositive", statistics.falsePositive()},
            {"trueNegative", statistics.trueNegative()},
            {"falseNegative", statistics.falseNegative()},
            {"sensitivity", statistics.sensitivity()},
            {"specificity", statistics.specificity()},
            {"accuracy", statistics.accuracy()}
    };
}

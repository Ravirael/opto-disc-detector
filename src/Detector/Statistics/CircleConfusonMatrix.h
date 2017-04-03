#pragma once


#include "ConfusionMatrix.h"
#include "../Geometry/Circle.h"

class CircleConfusionMatrix final: public ConfusionMatrix {
    unsigned mTruePositive;
    unsigned mTrueNegative;
    unsigned mFalsePositive;
    unsigned mFalseNegative;
public:
    CircleConfusionMatrix(Circle<int> real, Circle<int> detected, unsigned width, unsigned height);
    unsigned int truePositive() const override;
    unsigned int trueNegative() const override;
    unsigned int falsePositive() const override;
    unsigned int falseNegative() const override;
};



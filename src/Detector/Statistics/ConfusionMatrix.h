#pragma once


class ConfusionMatrix {
public:
    virtual unsigned truePositive() const = 0;
    virtual unsigned trueNegative() const = 0;
    virtual unsigned falsePositive() const = 0;
    virtual unsigned falseNegative() const = 0;
    virtual ~ConfusionMatrix() noexcept;
};



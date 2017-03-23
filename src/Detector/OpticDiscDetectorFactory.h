#pragma once


#include "OpticDiscDetector.h"

class OpticDiscDetectorFactory {
public:
    virtual std::unique_ptr<OpticDiscDetector> createDetector() const = 0;
    virtual ~OpticDiscDetectorFactory() noexcept;
};



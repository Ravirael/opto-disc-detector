#pragma once


#include "../Detector/OpticDiscDetectorFactory.h"
#include "ProgramArguments.h"

class ArgumentsAwareOpticDiscDetectorFactory final: public OpticDiscDetectorFactory {
    const ProgramArguments &mArguments;
public:
    ArgumentsAwareOpticDiscDetectorFactory(const ProgramArguments &arguments);
    std::unique_ptr<OpticDiscDetector> createDetector() const override;
};



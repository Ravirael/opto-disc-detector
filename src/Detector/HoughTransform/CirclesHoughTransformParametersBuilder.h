#pragma once
#include <memory>
#include "CirclesHoughTransformParameters.h"

class CirclesHoughTransformParametersBuilder {
public:
    virtual std::unique_ptr<CirclesHoughTransformParameters> build() = 0;
    virtual ~CirclesHoughTransformParametersBuilder() noexcept;
};



#pragma once
#include <memory>
#include "HoughParameters.h"

class HoughParametersFactory {
public:
    virtual std::unique_ptr<HoughParameters> create() const = 0;
    virtual ~HoughParametersFactory() noexcept;
};



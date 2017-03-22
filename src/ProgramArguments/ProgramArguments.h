#pragma once
#include <vector>
#include <string>
#include <boost/optional.hpp>
#include "../Geometry/Circle.h"

class ProgramArguments {

public:
    virtual std::string inputFilePath() const = 0;
    virtual boost::optional<Circle> expectedResult() const = 0;
    virtual ~ProgramArguments() noexcept;
};



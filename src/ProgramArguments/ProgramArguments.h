#pragma once
#include <vector>
#include <string>
#include <boost/optional.hpp>
#include "../Detector/Geometry/Circle.h"

class ProgramArguments {

public:
    virtual std::string inputFilePath() const = 0;
    virtual boost::optional<Circle<int>> expectedResult() const = 0;
    virtual bool debug() const = 0;
    virtual ~ProgramArguments() noexcept;
};



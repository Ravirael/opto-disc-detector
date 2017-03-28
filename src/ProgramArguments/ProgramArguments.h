#pragma once
#include <vector>
#include <string>
#include <boost/optional.hpp>
#include "../Detector/Geometry/Circle.h"
#include "../Detector/HoughTransform/HoughParametersFactory.h"

class ProgramArguments {
public:
    virtual std::string inputFilePath() const = 0;
    virtual boost::optional<std::string> outputFilePath() const = 0;
    virtual std::unique_ptr<HoughParametersFactory> houghParametersFactory() const = 0;
    virtual boost::optional<Circle<int>> expectedResult() const = 0;
    virtual bool debug() const = 0;
    virtual ~ProgramArguments() noexcept;
};



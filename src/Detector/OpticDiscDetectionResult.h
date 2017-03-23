#pragma once


#include <map>
#include <vector>
#include <boost/optional.hpp>
#include "../Detector/Geometry/Circle.h"

class OpticDiscDetectionResult {
public:
    virtual std::vector<Circle<int>> all() const = 0;
    virtual boost::optional<Circle<int>> best() const = 0;
    virtual ~OpticDiscDetectionResult() noexcept;
};



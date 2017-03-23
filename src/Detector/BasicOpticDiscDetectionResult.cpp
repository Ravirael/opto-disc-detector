#include "BasicOpticDiscDetectionResult.h"

BasicOpticDiscDetectionResult::BasicOpticDiscDetectionResult(std::vector<Circle<int>> circles) : mCircles(
        std::move(circles)) {

}

std::vector<Circle<int>> BasicOpticDiscDetectionResult::all() const {
    return mCircles;
}

boost::optional<Circle<int>> BasicOpticDiscDetectionResult::best() const {
    return (mCircles.empty() ?
            boost::optional<Circle<int>>() :
            boost::optional<Circle<int>>(mCircles.front()));
}

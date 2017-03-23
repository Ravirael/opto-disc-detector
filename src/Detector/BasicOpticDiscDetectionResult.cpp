#include "BasicOpticDiscDetectionResult.h"

BasicOpticDiscDetectionResult::BasicOpticDiscDetectionResult(std::vector<Circle<int>> circles) : mCircles(
        std::move(circles)) {

}

std::vector<Circle<int>> BasicOpticDiscDetectionResult::all() const {
    return mCircles;
}

Circle<int> BasicOpticDiscDetectionResult::best() const {
    return mCircles.front();
}

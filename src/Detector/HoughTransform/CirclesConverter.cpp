#include "CirclesConverter.h"
#include "../BasicOpticDiscDetectionResult.h"

std::unique_ptr<OpticDiscDetectionResult> CirclesConverter::operator()(std::vector<cv::Vec3f> input) const {
    std::vector<Circle<int>> output;

    for (const auto &vec : input) {
        output.emplace_back(Point<int>(vec[0], vec[1]), vec[2]);
    }

    return std::make_unique<BasicOpticDiscDetectionResult>(std::move(output));
}

#pragma once

#include <memory>
#include <opencv2/core/matx.hpp>
#include "../ProcessingStage.h"
#include "../OpticDiscDetectionResult.h"

class CirclesConverter final: public ProcessingStage<std::vector<cv::Vec3f>, std::unique_ptr<OpticDiscDetectionResult>> {
public:
    Result operator()(Argument arg) const override;
};



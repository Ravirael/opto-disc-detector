#pragma once


#include <memory>
#include <opencv2/core/mat.hpp>
#include "OpticDiscDetectionResult.h"
#include "ProcessingStage.h"

using OpticDiscDetector = ProcessingStage<cv::Mat, std::unique_ptr<OpticDiscDetectionResult>>;


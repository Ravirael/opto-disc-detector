#include "JsonHoughTransformParameters.h"
#include "PresetCirclesHoughTransformParametersBuilder.h"

JsonHoughTransformParameters::JsonHoughTransformParameters(const nlohmann::json &json) :
    mParameters(
            PresetCirclesHoughTransformParametersBuilder()
            .setAccumulatorThreshold(json.at("accumulatorThreshold"))
            .setRelativeMaxRadius(json.at("maxRadius"))
            .setRelativeMinRadius(json.at("minRadius"))
            .setRelativeMinDistance(json.at("minDistance"))
            .setUpperCannyThreshold(json.at("cannyThreshold"))
            .build()
    ) {

}

double JsonHoughTransformParameters::accumulatorResolutionRatio(const cv::Mat &input) const {
    return 0;
}

double JsonHoughTransformParameters::minDistance(const cv::Mat &input) const {
    return 0;
}

double JsonHoughTransformParameters::upperCannyThreshold(const cv::Mat &input) const {
    return 0;
}

double JsonHoughTransformParameters::minRadius(const cv::Mat &input) const {
    return 0;
}

double JsonHoughTransformParameters::maxRadius(const cv::Mat &input) const {
    return 0;
}

unsigned int JsonHoughTransformParameters::accumulatorThreshold(const cv::Mat &input) const {
    return 0;
}

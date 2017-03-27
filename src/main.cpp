#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <json.hpp>
#include "ProgramArguments/CommandLineArgumentsParser.h"
#include "ProgramArguments/ParsedProgramArguments.h"
#include "Detector/BasicOpticDiscDetectorFactory.h"
#include "Detector/DefaultStageFactory.h"
#include "Detector/EmptyProcessingStageDecorator.h"
#include "Detector/DecoratingStageFactory.h"
#include "Detector/DisplayingDecorator.h"
#include "Detector/DetectionResultRendered.h"

int main(int argc, char** argv) {
    ParsedProgramArguments options(
        std::make_unique<CommandLineArgumentsParser>(argc, argv));

    cv::Mat input = cv::imread(options.inputFilePath());
    std::unique_ptr<OpticDiscDetectorFactory> detectorFactory;

    if (options.debug()) {
        detectorFactory = std::make_unique<BasicOpticDiscDetectorFactory<DecoratingStageFactory<DisplayingDecorator>>>();
    } else {
        detectorFactory = std::make_unique<BasicOpticDiscDetectorFactory<>>();
    }

    const auto result = (*detectorFactory->createDetector())(input);

    if (options.debug()) {
        DisplayingDecorator(std::make_unique<DetectionResultRendered>(result.get()))(input);
    }

    const auto allCircles = result->all();
    const auto bestCircle = result->best();

    if (bestCircle) {
        std::cout << nlohmann::json(bestCircle.get());
        if (options.outputFilePath()) {
            cv::imwrite(options.outputFilePath().get(), DetectionResultRendered(result.get())(input));
        }
    } else {
        std::cout << nlohmann::json::object();
    }


    return 0;
}

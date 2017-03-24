#include <opencv2/imgcodecs.hpp>
#include <iostream>
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
        CommandLineArgumentsParser(argc, argv));

    cv::Mat input = cv::imread(options.inputFilePath());
    std::unique_ptr<OpticDiscDetectorFactory> detectorFactory;

    if (options.debug()) {
        detectorFactory = std::make_unique<BasicOpticDiscDetectorFactory<DecoratingStageFactory<DisplayingDecorator>>>();
    } else {
        detectorFactory = std::make_unique<BasicOpticDiscDetectorFactory<>>();
    }

    auto result = detectorFactory->createDetector()->operator()(input);

    if (options.debug()) {
        DisplayingDecorator(std::make_unique<DetectionResultRendered>(result.get()))(input);
    }

    auto allCircles = result->all();

    std::cout << "[\n";
    for (const auto &circle : allCircles) {
        std::cout << "{x: " << circle.center().x() << ", y: " << circle.center().y() << ", radius: " << circle.radius() << "},\n";
    }
    std::cout << "\n]";

    return 0;
}

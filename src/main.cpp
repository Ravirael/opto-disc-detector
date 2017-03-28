#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <json.hpp>
#include "ProgramArguments/CommandLineArguments.h"
#include "Detector/BasicOpticDiscDetectorFactory.h"
#include "Detector/EmptyProcessingStageDecorator.h"
#include "Detector/DecoratingStageFactory.h"
#include "Detector/DisplayingDecorator.h"
#include "Detector/DetectionResultRendered.h"
#include "ProgramArguments/PrintHelpException.h"

int main(int argc, char** argv) {
    try {
        const auto options = CommandLineArguments(argc, argv);

        cv::Mat input = cv::imread(options.inputFilePath());
        std::unique_ptr<OpticDiscDetectorFactory> detectorFactory;

        if (options.debug()) {
            detectorFactory = std::make_unique<BasicOpticDiscDetectorFactory<DecoratingStageFactory<DisplayingDecorator>>>(
                    options.houghParametersFactory());
        } else {
            detectorFactory = std::make_unique<BasicOpticDiscDetectorFactory<>>(options.houghParametersFactory());
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
            return 0;
        } else {
            std::cout << nlohmann::json::object();
            return 1;
        }
    } catch (const PrintHelpException &ex) {
        std::cout << ex.what() << std::endl;
        return 0;
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown exception!" << std::endl;
        return 1;
    }
}

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
#include "ProgramArguments/ArgumentsAwareOpticDiscDetectorFactory.h"

int main(int argc, char** argv) {
    try {
        const auto options = CommandLineArguments(argc, argv);
        const auto detector = ArgumentsAwareOpticDiscDetectorFactory(options).createDetector();
        const cv::Mat input = cv::imread(options.inputFilePath());
        const auto result = (*detector)(input);
        const auto bestCircle = result->best();

        if (options.debug()) {
            DisplayingDecorator(std::make_unique<DetectionResultRendered>(result.get()))(input);
        }

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

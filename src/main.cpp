#include <opencv2/imgcodecs.hpp>
#include "ProgramArguments/CommandLineArgumentsParser.h"
#include "ProcessingStages/PreProcessing/BasicPreProcessingStage.h"
#include "ProcessingStages/EdgeDetecion/CannyEdgeDetectionStage.h"
#include "BlockingListner.h"

int main(int argc, char** argv) {
    CommandLineArgumentsParser parser(argc, argv);
    auto options = parser.parse();

    BasicPreProcessingStage preProcessingStage;
    CannyEdgeDetectionStage cannyStage;
    std::unique_ptr<BlockingListner> listner;

    cv::Mat input = cv::imread(options->inputFilePath());
    if (options->debug()) {
        listner = std::make_unique<BlockingListner>();
        auto &listnerRef = *listner;
        preProcessingStage.connect([&listnerRef](std::string d, const cv::Mat mat){listnerRef(d, mat);});
        cannyStage.connect([&listnerRef](std::string d, const cv::Mat mat){listnerRef(d, mat);});
    }

    cannyStage(preProcessingStage(input));

    return 0;
}
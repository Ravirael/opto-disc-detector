#include "CommandLineArguments.h"
#include "PrintHelpException.h"
#include "../Detector/HoughTransform/PresetHoughParametersFactory.h"
#include <boost/program_options.hpp>

CommandLineArguments::CommandLineArguments(const int argc, CommandLineArguments::Argv argv) :
    mArgc(argc),
    mArgv(argv) {
    auto options = createOptionsDescription();
    boost::program_options::store(boost::program_options::command_line_parser(mArgc, mArgv).options(options).run(),
                                  mVm);

    if (mVm.count("help")) {
        std::stringstream stream;
        stream << std::setprecision(3) << options;
        throw PrintHelpException(stream.str());
    }
}

boost::program_options::options_description CommandLineArguments::createOptionsDescription() const {
     boost::program_options::options_description options("OpticDiscDetector");

    options.add_options()
            ("input,i", boost::program_options::value<std::string>()->required(), "Input image file path")
            ("output,o", boost::program_options::value<std::string>(), "Output imagfe file path")

            ("minRadius", boost::program_options::value<double>()->default_value(0.045), "Minimum radius, % of image width (0 - 1)")
            ("maxRadius", boost::program_options::value<double>()->default_value(0.065), "Maximum radius, % of image width (0 - 1)")
            ("minDistance", boost::program_options::value<double>()->default_value(0.14), "Minimum distance, % of image width (0 - 1)")
            ("cannyThreshold", boost::program_options::value<unsigned>()->default_value(80), "Upper threshold of Canny filter (0 - 255)")
            ("accumulatorThreshold", boost::program_options::value<unsigned>()->default_value(4), "Accumulator detection threshold ( > 0)")

            ("x", boost::program_options::value<unsigned>(), "x of correct circle center (0 - width)")
            ("y", boost::program_options::value<unsigned>(), "y of correct circle center (0 - width)")
            ("radius", boost::program_options::value<unsigned>(), "Radius of correct circle center (0 - width)")

            ("help,h", "Display help message")
            ("debug,d", "Display steps");

    return options;
}

std::string CommandLineArguments::inputFilePath() const {
    return mVm["input"].as<std::string>();
}

boost::optional<std::string> CommandLineArguments::outputFilePath() const {
    return (mVm.count("output") ?
            boost::optional<std::string>(mVm["output"].as<std::string>()) :
            boost::optional<std::string>());;
}

boost::optional<Circle<int>> CommandLineArguments::expectedResult() const {
    return (mVm.count("x") || mVm.count("y") || mVm.count("radius")) ?
           boost::optional<Circle<int>>(Circle<int>(Point<int>(mVm["x"].as<unsigned>(),
                                                               mVm["y"].as<unsigned>()),
                                                    mVm["radius"].as<unsigned>())) :
           boost::optional<Circle<int>>();;
}

bool CommandLineArguments::debug() const {
    return mVm.count("debug");
}

std::unique_ptr<HoughParametersFactory> CommandLineArguments::houghParametersFactory() const {
    auto builder = std::make_unique<PresetHoughParametersFactory>();
    (*builder)
            .setRelativeMinRadius(mVm["minRadius"].as<double>())
            .setRelativeMaxRadius(mVm["maxRadius"].as<double>())
            .setRelativeMinDistance(mVm["minDistance"].as<double>())
            .setUpperCannyThreshold(mVm["cannyThreshold"].as<unsigned>())
            .setAccumulatorThreshold(mVm["accumulatorThreshold"].as<unsigned>());

    return std::move(builder);
}

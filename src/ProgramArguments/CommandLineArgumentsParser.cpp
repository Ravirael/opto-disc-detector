#include "CommandLineArgumentsParser.h"
#include "ConstProgramArguments.h"

CommandLineArgumentsParser::CommandLineArgumentsParser(const int argc, CommandLineArgumentsParser::Argv argv) :
    mArgc(argc),
    mArgv(argv),
    mOptions("OpticDiscDetector") {


}

cxxopts::Options CommandLineArgumentsParser::createCxxOpts() const {
    cxxopts::Options options("OpticDiscDetector");

    options.add_options()
            ("i,input","Input image",cxxopts::value<std::string>());

    return options;
}

std::unique_ptr<ProgramArguments> CommandLineArgumentsParser::parse() const {
    int argc = mArgc;
    Argv argv = mArgv;
    auto options = createCxxOpts();

    options.parse(argc, argv);

    auto filePath = options["input"].as<std::string>();

    return std::make_unique<ConstProgramArguments>(filePath, boost::optional<Circle>());
}

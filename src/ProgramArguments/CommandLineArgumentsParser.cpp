#include "CommandLineArgumentsParser.h"
#include "ConstProgramArguments.h"
#include <boost/program_options.hpp>

CommandLineArgumentsParser::CommandLineArgumentsParser(const int argc, CommandLineArgumentsParser::Argv argv) :
    mArgc(argc),
    mArgv(argv) {


}

boost::program_options::options_description CommandLineArgumentsParser::createOptionsDescription() const {
     boost::program_options::options_description options("OpticDiscDetector");

    options.add_options()
            ("debug,d", "Display steps")
            ("input,i", boost::program_options::value<std::string>()->required(), "Input image");

    return options;
}

std::unique_ptr<ProgramArguments> CommandLineArgumentsParser::parse() const {
    auto options = createOptionsDescription();
    boost::program_options::variables_map vm;

    boost::program_options::store(boost::program_options::command_line_parser(mArgc, mArgv).options(options).run(),
              vm);


    auto filePath = vm["input"].as<std::string>();
    auto debug = vm.count("debug");

    return std::make_unique<ConstProgramArguments>(filePath, vm.count("debug") > 0, boost::optional<Circle<int>>());
}

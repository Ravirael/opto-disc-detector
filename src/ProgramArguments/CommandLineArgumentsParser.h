#pragma once
#include "ProgramArgumentsParser.h"
#include "ConstProgramArguments.h"
#include <boost/program_options/options_description.hpp>

class CommandLineArgumentsParser : public ProgramArgumentsParser {
    using Argv = const char * const *;
    const int mArgc;
    const Argv mArgv;
public:
    CommandLineArgumentsParser(const int argc, Argv argv);
    std::unique_ptr<ProgramArguments> parse() const override;
private:
    boost::program_options::options_description createOptionsDescription() const;
};



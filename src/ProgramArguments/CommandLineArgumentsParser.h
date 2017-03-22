#pragma once
#include "ProgramArgumentsParser.h"
#include "ConstProgramArguments.h"
#include <cxxopts.hpp>

class CommandLineArgumentsParser : public ProgramArgumentsParser {
    using Argv = char **;
    const int mArgc;
    const Argv mArgv;
    cxxopts::Options mOptions;
public:
    CommandLineArgumentsParser(const int argc, Argv argv);
    std::unique_ptr<ProgramArguments> parse() const override;
private:
    cxxopts::Options createCxxOpts() const;
};



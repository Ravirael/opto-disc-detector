#pragma once
#include "ProgramArguments.h"

class ProgramArgumentsParser;

class ParsedProgramArguments final : public ProgramArguments {
    const ProgramArgumentsParser &mArgumentsParser;

public:
    ParsedProgramArguments(const ProgramArgumentsParser &argumentsParser);
    std::string inputFilePath() const override;
    boost::optional<Circle<int>> expectedResult() const override;
    bool debug() const override;
};



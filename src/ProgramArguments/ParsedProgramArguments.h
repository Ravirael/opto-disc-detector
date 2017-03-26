#pragma once
#include "ProgramArguments.h"
#include <memory>

class ProgramArgumentsParser;

class ParsedProgramArguments final : public ProgramArguments {
    const std::unique_ptr< const ProgramArgumentsParser > mArgumentsParser;

public:
    ParsedProgramArguments(
        std::unique_ptr< const ProgramArgumentsParser > &&argumentsParser);
    std::string inputFilePath() const override;
    boost::optional<Circle<int>> expectedResult() const override;
    bool debug() const override;
};



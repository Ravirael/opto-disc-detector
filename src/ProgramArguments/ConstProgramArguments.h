#pragma once


#include "ProgramArguments.h"

class ConstProgramArguments : public ProgramArguments {
    const std::string mInputFilePath;
    const boost::optional<std::string> mOutputFilePath;
    const bool mDebug;
    const boost::optional<Circle<int>> mExpectedResult;

public:
    ConstProgramArguments(const std::string &inputFilePath,
                              const boost::optional<std::string> outputFilePath, const bool debug,
                              const boost::optional<Circle<int>> &expectedResult);
    std::string inputFilePath() const override;
    boost::optional<std::string> outputFilePath() const override;
    bool debug() const override;
    boost::optional<Circle<int>> expectedResult() const override;

};



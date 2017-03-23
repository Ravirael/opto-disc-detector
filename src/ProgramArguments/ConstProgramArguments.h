#pragma once


#include "ProgramArguments.h"

class ConstProgramArguments : public ProgramArguments {
    const std::string mInputFilePath;
    const bool mDebug;
    const boost::optional<Circle<int>> mExpectedResult;

public:
    ConstProgramArguments(const std::string &inputFilePath, const bool debug,
                              const boost::optional<Circle<int>> &expectedResult);
    std::string inputFilePath() const override;
    bool debug() const override;
    boost::optional<Circle<int>> expectedResult() const override;
};



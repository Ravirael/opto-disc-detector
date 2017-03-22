#pragma once


#include "ProgramArguments.h"

class ConstProgramArguments : public ProgramArguments {
    const std::string mInputFilePath;
    const boost::optional<Circle> mExpectedResult;

public:
    ConstProgramArguments(const std::string &inputFilePath, const boost::optional<Circle> &expectedResult);
    std::string inputFilePath() const override;
    boost::optional<Circle> expectedResult() const override;
};



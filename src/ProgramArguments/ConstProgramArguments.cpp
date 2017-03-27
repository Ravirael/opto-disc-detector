#include "ConstProgramArguments.h"

ConstProgramArguments::ConstProgramArguments(const std::string &inputFilePath,
                                             const boost::optional<std::string> outputFilePath, const bool debug,
                                             const boost::optional<Circle<int>> &expectedResult) :
        mInputFilePath(inputFilePath),
        mOutputFilePath(std::move(outputFilePath)),
        mExpectedResult(expectedResult),
        mDebug(debug) {

}

std::string ConstProgramArguments::inputFilePath() const {
    return mInputFilePath;
}

boost::optional<Circle<int>> ConstProgramArguments::expectedResult() const {
    return mExpectedResult;
}

bool ConstProgramArguments::debug() const {
    return mDebug;
}

boost::optional<std::string> ConstProgramArguments::outputFilePath() const {
    return mOutputFilePath;
}

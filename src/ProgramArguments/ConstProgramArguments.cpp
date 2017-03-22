#include "ConstProgramArguments.h"

ConstProgramArguments::ConstProgramArguments(const std::string &inputFilePath,
                                             const boost::optional<Circle> &expectedResult) :
        mInputFilePath(inputFilePath),
        mExpectedResult(expectedResult) {

}

std::string ConstProgramArguments::inputFilePath() const {
    return mInputFilePath;
}

boost::optional<Circle> ConstProgramArguments::expectedResult() const {
    return mExpectedResult;
}

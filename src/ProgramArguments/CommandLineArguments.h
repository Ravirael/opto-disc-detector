#pragma once
#include "ProgramArguments.h"
#include "../Detector/HoughTransform/HoughParametersFactory.h"
#include "../Detector/Geometry/Circle.h"
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/optional.hpp>

class CommandLineArguments final: public ProgramArguments {
    using Argv = const char * const *;
    const int mArgc;
    const Argv mArgv;
    boost::program_options::variables_map mVm;
public:
    CommandLineArguments(const int argc, Argv argv);
    std::string inputFilePath() const override;
    boost::optional<std::string> outputFilePath() const override;
    std::unique_ptr<HoughParametersFactory> houghParametersFactory() const override;
    boost::optional<Circle<int>> expectedResult() const override;
    double blurSize() const override;
    double blurSigma() const override;
    bool debug() const override;

private:
    boost::program_options::options_description createOptionsDescription() const;
};



#include "ParsedProgramArguments.h"
#include "ProgramArgumentsParser.h"

ParsedProgramArguments::ParsedProgramArguments(
    const ProgramArgumentsParser &argumentsParser) 
  : mArgumentsParser(argumentsParser) {
  
}

std::string ParsedProgramArguments::inputFilePath() const{
  return mArgumentsParser.parse()->inputFilePath(); 
}

boost::optional<Circle<int>> ParsedProgramArguments::expectedResult() const{
  return mArgumentsParser.parse()->expectedResult(); 
}

bool ParsedProgramArguments::debug() const{
  return mArgumentsParser.parse()->debug(); 
}


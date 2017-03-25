#include "ParsedProgramArguments.h"
#include "ProgramArgumentsParser.h"

ParsedProgramArguments::ParsedProgramArguments(
    std::unique_ptr< const ProgramArgumentsParser > &&argumentsParser) 
  : mArgumentsParser(std::move(argumentsParser)) {
  
}

std::string ParsedProgramArguments::inputFilePath() const{
  return mArgumentsParser->parse()->inputFilePath(); 
}

boost::optional<Circle<int>> ParsedProgramArguments::expectedResult() const{
  return mArgumentsParser->parse()->expectedResult(); 
}

bool ParsedProgramArguments::debug() const{
  return mArgumentsParser->parse()->debug(); 
}


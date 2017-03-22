#pragma once
#include <memory>

class ProgramArguments;

class ProgramArgumentsParser {
public:
    virtual std::unique_ptr<ProgramArguments> parse() const = 0;
    virtual ~ProgramArgumentsParser() noexcept;
};



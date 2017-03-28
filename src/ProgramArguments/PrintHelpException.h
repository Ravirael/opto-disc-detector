#pragma once

#include <string>
#include <exception>

class PrintHelpException final: public std::exception {
    const std::string mHelpMessage;
public:
    PrintHelpException(std::string helpMessage);
    const char *what() const noexcept override;
};



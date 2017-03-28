#include "PrintHelpException.h"

PrintHelpException::PrintHelpException(std::string helpMessage) :
    mHelpMessage(std::move(helpMessage)) {

}

const char *PrintHelpException::what() const noexcept {
    return mHelpMessage.c_str();
}

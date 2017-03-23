#include <opencv2/imgcodecs.hpp>
#include "ProgramArguments/CommandLineArgumentsParser.h"

int main(int argc, char** argv) {
    CommandLineArgumentsParser parser(argc, argv);
    auto options = parser.parse();


    return 0;
}
#include "ProgramArguments/CommandLineArgumentsParser.h"

int main(int argc, char** argv) {
    CommandLineArgumentsParser parser(argc, argv);
    parser.parse();

    return 0;
}
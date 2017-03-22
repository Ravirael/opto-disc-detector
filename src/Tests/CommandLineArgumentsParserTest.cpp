#include <catch.hpp>
#include "../ProgramArguments/CommandLineArgumentsParser.h"
#include <cstring>

namespace {
    class ToArgvConverter {
        const std::size_t mCount;
        char **mArgv;
    public:
        ToArgvConverter(std::vector<std::string> argv) :
                mCount(argv.size()) {
            mArgv = new char*[argv.size()];

            for (std::size_t i = 0u; i < argv.size(); ++i) {
                mArgv[i] = new char[argv.at(i).size() + 1];
                std::strcpy(mArgv[i], argv.at(i).c_str());
            }
        }

        char **argv() {
            return mArgv;
        }

        int argc() {
            return mCount;
        }

        ~ToArgvConverter() {
            for (std::size_t i = 0u; i < mCount; ++i) {
                delete [] mArgv[i];
            }
            delete [] mArgv;
        }

    };
}

TEST_CASE("command line arguments can be parsed", "[CommandLineArgumentsParser]") {
    const std::string filePath = "/path/to/file.jpg";

    SECTION("parsing command line argument with correct -i option") {
        ToArgvConverter converter({"program","-i",filePath});
        CommandLineArgumentsParser parser(converter.argc(), converter.argv());
        CHECK(filePath == parser.parse()->inputFilePath());
    }

    SECTION("parsing command line argument with correct --input option") {
        ToArgvConverter converter({"program","--input",filePath});
        CommandLineArgumentsParser parser(converter.argc(), converter.argv());
        CHECK(filePath == parser.parse()->inputFilePath());
    }

    SECTION("parsing command line argument with correct --input= option") {
        ToArgvConverter converter({"program","--input="+filePath});
        CommandLineArgumentsParser parser(converter.argc(), converter.argv());
        CHECK(filePath == parser.parse()->inputFilePath());
    }
}
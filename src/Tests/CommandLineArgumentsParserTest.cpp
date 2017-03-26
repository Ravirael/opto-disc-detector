#include <catch.hpp>
#include "../ProgramArguments/CommandLineArgumentsParser.h"
#include "../ProgramArguments/ProgramArguments.h"
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
        auto args = parser.parse();
        CHECK(filePath == args->inputFilePath());
        CHECK_FALSE(args->debug());
    }

    SECTION("parsing command line argument with correct --input option") {
        ToArgvConverter converter({"program","--input",filePath});
        CommandLineArgumentsParser parser(converter.argc(), converter.argv());
        auto args = parser.parse();
        CHECK(filePath == args->inputFilePath());
        CHECK_FALSE(args->debug());
    }

    SECTION("parsing command line argument with correct --input= option") {
        ToArgvConverter converter({"program","--input="+filePath});
        CommandLineArgumentsParser parser(converter.argc(), converter.argv());
        auto args = parser.parse();
        CHECK(filePath == args->inputFilePath());
        CHECK_FALSE(args->debug());
    }

    SECTION("parsing command line argument with --debug option") {
        ToArgvConverter converter({"program","--debug","--input",filePath});
        CommandLineArgumentsParser parser(converter.argc(), converter.argv());
        auto args = parser.parse();
        CHECK(filePath == args->inputFilePath());
        CHECK(args->debug());
    }

    SECTION("parsing command line argument with -d option") {
        ToArgvConverter converter({"program","--input",filePath,"-d"});
        CommandLineArgumentsParser parser(converter.argc(), converter.argv());
        auto args = parser.parse();
        CHECK(filePath == args->inputFilePath());
        CHECK(args->debug());
    }
}

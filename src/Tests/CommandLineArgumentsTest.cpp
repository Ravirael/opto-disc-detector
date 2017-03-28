#include <catch.hpp>
#include "../ProgramArguments/CommandLineArguments.h"
#include "../ProgramArguments/ProgramArguments.h"
#include "../ProgramArguments/PrintHelpException.h"
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

    CommandLineArguments createArguments(std::vector<std::string> argv) {
        ToArgvConverter converter(std::move(argv));
        return CommandLineArguments(converter.argc(), converter.argv());
    }
}

TEST_CASE("command line arguments can be parsed", "[CommandLineArguments]") {
    const std::string filePath = "/path/to/file.jpg";

    SECTION("parsing command line argument with correct -i option") {
        auto args = createArguments({"program","-i",filePath});
        CHECK(filePath == args.inputFilePath());
        CHECK_FALSE(args.debug());
    }

    SECTION("parsing command line argument with correct --input option") {
        auto args = createArguments({"program","--input",filePath});
        CHECK(filePath == args.inputFilePath());
        CHECK_FALSE(args.debug());
    }

    SECTION("parsing command line argument with correct --input= option") {
        auto args = createArguments({"program","--input="+filePath});
        CHECK(filePath == args.inputFilePath());
        CHECK_FALSE(args.debug());
    }

    SECTION("parsing command line argument with --debug option") {
        auto args = createArguments({"program","--debug","--input",filePath});
        CHECK(filePath == args.inputFilePath());
        CHECK(args.debug());
    }

    SECTION("parsing command line argument with -d option") {
        auto args = createArguments({"program","--input",filePath,"-d"});
        CHECK(filePath == args.inputFilePath());
        CHECK(args.debug());
    }

    SECTION("parsing command line arguments with -h option") {
        try {
            auto args = createArguments({"program","--input",filePath,"-h"});
            INFO("Parsing doesn't throw PrintHelpExeption.");
            CHECK(false);
        } catch (const PrintHelpException &ex) {
            CHECK(!std::string(ex.what()).empty());
        }
    }

    SECTION("command line arguments with --x but without --y should throw while getting expected circle") {
        auto args = createArguments({"program","--input",filePath,"--x","120"});
        CHECK_THROWS(args.expectedResult());
    }

    SECTION("command line arguments with --x, --y without --radius should throw while getting expected circle") {
        auto args = createArguments({"program","--input",filePath,"--x","120","--y","120"});
        CHECK_THROWS(args.expectedResult());
    }

    SECTION("command line arguments correct expected circle") {
        auto args = createArguments({"program","--input",filePath,"--x","120","--y","140","--radius","50"});
        CHECK(120 == args.expectedResult()->center().x());
        CHECK(140 == args.expectedResult()->center().y());
        CHECK(50 == args.expectedResult()->radius());
    }
}

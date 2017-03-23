#include <catch.hpp>
#include "../Detector/ProcessingStage.h"
#include "../Detector/ProcessingStageComposite.h"

namespace {
    struct TwofoldToString : public ProcessingStage<int, std::string> {
        std::string operator()(int arg) const override {
            return std::to_string(2*arg);
        }
    };

    struct StringToInt : public ProcessingStage<std::string, int> {
        int operator()(std::string arg) const override {
            return std::stoi(arg);
        }
    };
}

TEST_CASE("processing stages can be composed", "[ProcessingStageComposite]") {
    SECTION("composing two stages via constructor call") {
        const int testCase = 4;
        auto composite = std::make_unique<ProcessingStageComposite<int, std::string, int>>(
                std::make_unique<TwofoldToString>(),
                std::make_unique<StringToInt>()
        );

        CHECK(testCase * 2 ==  (*composite)(testCase));
    }

    SECTION("composing two stages via operator|") {
        const int testCase = 4;
        auto composite = std::make_unique<TwofoldToString>() | std::make_unique<StringToInt>();
        CHECK(testCase * 2 ==  (*composite)(testCase));
    }

    SECTION("composing four stages via operator|") {
        const int testCase = 4;
        auto composite = std::make_unique<TwofoldToString>()
                         | std::make_unique<StringToInt>()
                         | std::make_unique<TwofoldToString>()
                         | std::make_unique<StringToInt>();
        CHECK(testCase * 4 ==  (*composite)(testCase));
    }
}
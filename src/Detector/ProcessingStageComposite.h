#pragma once

#include <bits/unique_ptr.h>
#include "ProcessingStage.h"

template <typename Argument, typename SubResult = Argument, typename Result = SubResult>
class ProcessingStageComposite final: public ProcessingStage<Argument, Result> {
    using FirstStage = ProcessingStage<Argument, SubResult>;
    using SecondStage = ProcessingStage<SubResult, Result>;

    std::unique_ptr<FirstStage> mFirst;
    std::unique_ptr<SecondStage> mSecond;

public:
    ProcessingStageComposite(std::unique_ptr<FirstStage> &&first, std::unique_ptr<SecondStage> &&second) :
            mFirst(std::move(first)),
            mSecond(std::move(second)) {

    }

    Result operator()(Argument arg) const override {
        return (*mSecond)((*mFirst)(arg));
    }
};

//Sick but works!
template <typename First, typename Second,
        typename Argument = typename First::Argument, typename SubResult = typename First::Result, typename Result = typename Second::Result>
std::unique_ptr<ProcessingStageComposite<Argument, SubResult, Result>>
operator|(std::unique_ptr<First> &&lhs, std::unique_ptr<Second> &&rhs) {
    return std::make_unique<ProcessingStageComposite<Argument, SubResult, Result>>(std::move(lhs), std::move(rhs));
};

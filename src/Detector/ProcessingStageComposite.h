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

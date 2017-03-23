#pragma once

#include <memory>
#include "ProcessingStage.h"

template <typename A, typename R = A>
class ProcessingStageDecorator : public ProcessingStage<A, R> {
    std::unique_ptr<ProcessingStage<A, R>> mDecorated;

public:
    ProcessingStageDecorator(std::unique_ptr<ProcessingStage<A, R>> &&decorated) :
            mDecorated(std::move(decorated)) {

    }

    virtual typename ProcessingStage<A, R>::Result operator()(typename ProcessingStage<A, R>::Argument arg) const override = 0;
};

template <typename A, typename R>
typename ProcessingStage<A, R>::Result ProcessingStageDecorator<A, R>::operator()(typename ProcessingStage<A, R>::Argument arg) const {
    return (*mDecorated)(std::move(arg));
}
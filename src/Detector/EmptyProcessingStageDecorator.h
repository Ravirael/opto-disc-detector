#pragma once

#include "ProcessingStageDecorator.h"

template <typename A, typename R = A>
class EmptyProcessingStageDecorator final: public ProcessingStageDecorator<A, R> {
public:
    using ProcessingStageDecorator<A, R>::ProcessingStageDecorator;

    R operator()(A arg) const override {
        return ProcessingStageDecorator<A, R>::operator()(std::move(arg));
    }
};



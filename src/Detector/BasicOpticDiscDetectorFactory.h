#pragma once

#include "OpticDiscDetectorFactory.h"
#include "ProcessingStageComposite.h"
#include "PreProcessing/PreProcessingStage.h"
#include "HoughTransform/HoughTransformStage.h"
#include "HoughTransform/CirclesConverter.h"
#include "DefaultStageFactory.h"
#include "EdgeDetecion/EdgeDetectionStage.h"

template <typename StageFactory = DefaultStageFactory>
class BasicOpticDiscDetectorFactory final: public OpticDiscDetectorFactory {
    const StageFactory mStageFactory;

public:
    template <typename ... Args>
    BasicOpticDiscDetectorFactory(Args && ... args) :
            mStageFactory(std::forward<Args>(args)...) {

    }

    std::unique_ptr<OpticDiscDetector> createDetector() const override {
        return create<PreProcessingStage>()
               | create<EdgeDetectionStage>()
               | create<HoughTransformStage>()
               | create<CirclesConverter>();
    }

private:
    template <typename T, typename ... Args>
    auto create(Args && ... args) const {
        return mStageFactory.template create<T>(std::forward<Args>(args)...);
    }
};
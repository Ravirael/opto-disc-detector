#pragma once

#include "OpticDiscDetectorFactory.h"
#include "ProcessingStageComposite.h"
#include "PreProcessing/BasicPreProcessingStage.h"
#include "HoughTransform/HoughTransformStage.h"
#include "HoughTransform/CirclesConverter.h"
#include "DefaultStageFactory.h"

template <typename StageFactory = DefaultStageFactory>
class BasicOpticDiscDetectorFactory : public OpticDiscDetectorFactory {
    const StageFactory mStageFactory;

public:
    template <typename ... Args>
    BasicOpticDiscDetectorFactory(Args && ... args) :
            mStageFactory(std::forward<Args>(args)...) {

    }

    std::unique_ptr<OpticDiscDetector> createDetector() const override {
        return mStageFactory.template create<BasicPreProcessingStage>()
                | mStageFactory.template create<HoughTransformStage>()
                | mStageFactory.template create<CirclesConverter>();
    }
};
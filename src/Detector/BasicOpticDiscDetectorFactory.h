#pragma once

#include "OpticDiscDetectorFactory.h"
#include "ProcessingStageComposite.h"
#include "PreProcessing/PreProcessingStage.h"
#include "Adapters/CirclesHoughTransform.h"
#include "HoughTransform/CirclesConverter.h"
#include "DefaultStageFactory.h"
#include "EdgeDetecion/EdgeDetectionStage.h"
#include "Adapters/ToGrayscale.h"
#include "PreProcessing/ThresholdingStage.h"
#include "PreProcessing/MorphologicalStage.h"
#include "Adapters/HistogramEqualization.h"
#include "Adapters/ChannelSelection.h"
#include "Adapters/PresetCirclesHoughTransformParameters.h"

template <typename StageFactory = DefaultStageFactory>
class BasicOpticDiscDetectorFactory final: public OpticDiscDetectorFactory {
    const StageFactory mStageFactory;

public:
    template <typename ... Args>
    BasicOpticDiscDetectorFactory(Args && ... args) :
            mStageFactory(std::forward<Args>(args)...) {

    }

    std::unique_ptr<OpticDiscDetector> createDetector() const override {
        return create<ChannelSelection>(ChannelSelection::R)
               | create<HistogramEqualization>()
               | create<ToGrayscale>()
               | create<ThresholdingStage>()
               | create<MorphologicalStage>()
               | create<CirclesHoughTransform>(
                PresetCirclesHoughTransformParametersBuilder()
                            .setUpperCannyThreshold(100)
                            .setRelativeMinRadius(0.04)
                            .setRelativeMaxRadius(0.07)
                            .setRelativeMinDistance(0.02)
                            .setAccumulatorThreshold(10)
                            .build()
                )
               | create<CirclesConverter>();
    }

private:
    template <typename T, typename ... Args>
    auto create(Args && ... args) const {
        return mStageFactory.template create<T>(std::forward<Args>(args)...);
    }
};
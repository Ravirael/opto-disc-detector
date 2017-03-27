#pragma once

#include "OpticDiscDetectorFactory.h"
#include "ProcessingStageComposite.h"
#include "PreProcessing/PreProcessingStage.h"
#include "Adapters/CirclesHoughTransform.h"
#include "HoughTransform/CirclesConverter.h"
#include "DefaultStageFactory.h"
#include "EdgeDetecion/EdgeDetectionStage.h"
#include "Adapters/ToGrayscale.h"
#include "Adapters/GlobalThreshold.h"
#include "PreProcessing/MorphologicalStage.h"
#include "Adapters/HistogramEqualization.h"
#include "Adapters/ChannelSelection.h"
#include "Adapters/PresetCirclesHoughTransformParameters.h"
#include "Adapters/Canny.h"
#include "Adapters/MinMaxNormalize.h"
#include "Adapters/GaussianBlur.h"

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
               | create<GaussianBlur>(0.05, 10.0)
               | create<HistogramEqualization>()
               | create<MinMaxNormalize>(16)
               | create<CirclesHoughTransform>(
                PresetCirclesHoughTransformParametersBuilder()
                            .setUpperCannyThreshold(80)
                            .setRelativeMinRadius(0.045)
                            .setRelativeMaxRadius(0.065)
                            .setRelativeMinDistance(0.14)
                            .setAccumulatorThreshold(4)
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
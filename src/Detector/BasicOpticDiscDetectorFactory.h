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
#include "HoughTransform/PresetHoughParametersFactory.h"
#include "Adapters/Canny.h"
#include "Adapters/MinMaxNormalize.h"
#include "Adapters/GaussianBlur.h"
#include "TrimBorder.h"

template <typename StageFactory = DefaultStageFactory>
class BasicOpticDiscDetectorFactory final: public OpticDiscDetectorFactory {
    const StageFactory mStageFactory;
    const std::unique_ptr<HoughParametersFactory> mHoughParametersFactory;
    const double mBlurSize;
    const double mBlurSigma;

public:
    template <typename ... Args>
    BasicOpticDiscDetectorFactory(std::unique_ptr<HoughParametersFactory> houghParametersFactory, double blurSize, double blurSigma, Args && ... args) :
            mStageFactory(std::forward<Args>(args)...),
            mHoughParametersFactory(std::move(houghParametersFactory)),
            mBlurSize(blurSize),
            mBlurSigma(blurSigma) {

    }

    std::unique_ptr<OpticDiscDetector> createDetector() const override {
        return  create<ChannelSelection>(ChannelSelection::R)
               | create<GaussianBlur>(mBlurSize, mBlurSigma)
               | create<HistogramEqualization>()
               | create<MinMaxNormalize>(16)
               | create<CirclesHoughTransform>(mHoughParametersFactory->create())
               | create<CirclesConverter>();
    }

private:
    template <typename T, typename ... Args>
    auto create(Args && ... args) const {
        return mStageFactory.template create<T>(std::forward<Args>(args)...);
    }
};
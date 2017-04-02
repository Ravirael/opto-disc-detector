#include "ArgumentsAwareOpticDiscDetectorFactory.h"
#include "../Detector/BasicOpticDiscDetectorFactory.h"
#include "../Detector/DecoratingStageFactory.h"
#include "../Detector/DisplayingDecorator.h"

namespace {
    template <typename ... Args>
    std::unique_ptr<OpticDiscDetectorFactory> createFactory(bool debug, Args && ... args) {
        if (debug) {
            return std::make_unique<BasicOpticDiscDetectorFactory<DecoratingStageFactory<DisplayingDecorator>>>(
                    std::forward<Args>(args)...
            );
        } else {
            return std::make_unique<BasicOpticDiscDetectorFactory<>>(
                    std::forward<Args>(args)...
            );
        }
    }
}

ArgumentsAwareOpticDiscDetectorFactory::ArgumentsAwareOpticDiscDetectorFactory(const ProgramArguments &arguments)
        : mArguments(arguments) {

}

std::unique_ptr<OpticDiscDetector> ArgumentsAwareOpticDiscDetectorFactory::createDetector() const {
     auto factory = createFactory(
        mArguments.debug(),
        mArguments.houghParametersFactory(),
        mArguments.blurSize(),
        mArguments.blurSigma()
    );
    return factory->createDetector();
}

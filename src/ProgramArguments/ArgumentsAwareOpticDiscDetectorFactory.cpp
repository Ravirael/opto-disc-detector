#include "ArgumentsAwareOpticDiscDetectorFactory.h"
#include "../Detector/BasicOpticDiscDetectorFactory.h"
#include "../Detector/DecoratingStageFactory.h"
#include "../Detector/DisplayingDecorator.h"

ArgumentsAwareOpticDiscDetectorFactory::ArgumentsAwareOpticDiscDetectorFactory(const ProgramArguments &arguments)
        : mArguments(arguments) {

}

std::unique_ptr<OpticDiscDetector> ArgumentsAwareOpticDiscDetectorFactory::createDetector() const {
     std::unique_ptr<OpticDiscDetectorFactory> factory;
    if (mArguments.debug()) {
        factory = std::make_unique<BasicOpticDiscDetectorFactory<DecoratingStageFactory<DisplayingDecorator>>>(
                mArguments.houghParametersFactory());
    } else {
        factory = std::make_unique<BasicOpticDiscDetectorFactory<>>(mArguments.houghParametersFactory());
    }
    return factory->createDetector();
}

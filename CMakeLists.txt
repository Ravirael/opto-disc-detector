cmake_minimum_required(VERSION 3.0)
project(optic-disc-detector VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 14)

# Set a default create type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of create type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
            "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include_directories(src/External)
set(LIBS opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs boost_program_options)

set(SOURCE_FILES src/ProgramArguments/ProgramArguments.cpp src/ProgramArguments/ProgramArguments.h src/Detector/Geometry/Circle.h src/ProgramArguments/CommandLineArguments.cpp src/ProgramArguments/CommandLineArguments.h src/Detector/EdgeDetecion/EdgeDetectionStage.cpp src/Detector/EdgeDetecion/EdgeDetectionStage.h src/Detector/Geometry/Point.h src/Detector/PreProcessing/PreProcessingStage.cpp src/Detector/PreProcessing/PreProcessingStage.h src/Detector/OpticDiscDetector.h src/Detector/ProcessingStage.h src/Detector/ImageProcessingStage.h src/Detector/ProcessingStageComposite.h src/Detector/OpticDiscDetectorFactory.cpp src/Detector/OpticDiscDetectorFactory.h src/Detector/BasicOpticDiscDetectorFactory.h src/Detector/DefaultStageFactory.h src/Detector/BasicOpticDiscDetectionResult.cpp src/Detector/BasicOpticDiscDetectionResult.h src/Detector/HoughTransform/CirclesConverter.cpp src/Detector/HoughTransform/CirclesConverter.h src/Detector/OpticDiscDetectionResult.cpp src/Detector/OpticDiscDetectionResult.h src/Detector/Adapters/CirclesHoughTransform.cpp src/Detector/Adapters/CirclesHoughTransform.h src/Detector/DecoratingStageFactory.h src/Detector/ProcessingStageDecorator.h src/Detector/EmptyProcessingStageDecorator.cpp src/Detector/EmptyProcessingStageDecorator.h src/Detector/DisplayingDecorator.cpp src/Detector/DisplayingDecorator.h src/Detector/DetectionResultRendered.cpp src/Detector/DetectionResultRendered.h src/Detector/Adapters/ToGrayscale.cpp src/Detector/Adapters/ToGrayscale.h src/Detector/Adapters/GlobalThreshold.cpp src/Detector/Adapters/GlobalThreshold.h src/Detector/PreProcessing/MorphologicalStage.cpp src/Detector/PreProcessing/MorphologicalStage.h src/Detector/Adapters/HistogramEqualization.cpp src/Detector/Adapters/HistogramEqualization.h src/Detector/Adapters/ChannelSelection.cpp src/Detector/Adapters/ChannelSelection.h src/Detector/HoughTransform/HoughParameters.cpp src/Detector/HoughTransform/HoughParameters.h src/Detector/HoughTransform/PresetHoughParameters.cpp src/Detector/HoughTransform/PresetHoughParameters.h src/Detector/Adapters/MinMaxNormalize.cpp src/Detector/Adapters/MinMaxNormalize.h src/Detector/Adapters/Canny.cpp src/Detector/Adapters/Canny.h src/Detector/Adapters/GaussianBlur.cpp src/Detector/Adapters/GaussianBlur.h src/Detector/HoughTransform/PresetHoughParametersFactory.cpp src/Detector/HoughTransform/PresetHoughParametersFactory.h src/Detector/HoughTransform/HoughParametersFactory.cpp src/Detector/HoughTransform/HoughParametersFactory.h src/ProgramArguments/PrintHelpException.cpp src/ProgramArguments/PrintHelpException.h src/Detector/CvNamedWindow.cpp src/Detector/CvNamedWindow.h src/ProgramArguments/ArgumentsAwareOpticDiscDetectorFactory.cpp src/ProgramArguments/ArgumentsAwareOpticDiscDetectorFactory.h src/Detector/Statistics/ConfusionMatrix.cpp src/Detector/Statistics/ConfusionMatrix.h src/Detector/Statistics/ConfusionMatrixStatistics.cpp src/Detector/Statistics/ConfusionMatrixStatistics.h src/Detector/Statistics/CircleConfusionMatrix.cpp src/Detector/Statistics/CircleConfusionMatrix.h src/Detector/TrimBorder.cpp src/Detector/TrimBorder.h)
set(TEST_SOURCE_FILES src/Tests/CommandLineArgumentsTest.cpp src/Tests/ProcessingStageCompositeTest.cpp)

add_executable(optic-disc-detector ${SOURCE_FILES} src/main.cpp)
target_link_libraries(optic-disc-detector ${LIBS})

add_executable(optic-disc-detector-test ${SOURCE_FILES} ${TEST_SOURCE_FILES} src/test.cpp)
target_link_libraries(optic-disc-detector-test ${LIBS})

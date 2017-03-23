cmake_minimum_required(VERSION 3.0)
project(optic-disc-detector VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 14)

# Set a default build type if none was specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
            "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ggdb -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

include_directories(src/External)
set(LIBS opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs boost_program_options)

set(SOURCE_FILES src/ProgramArguments/ProgramArguments.cpp src/ProgramArguments/ProgramArguments.h src/Detector/Geometry/Circle.h src/ProgramArguments/ProgramArgumentsParser.cpp src/ProgramArguments/ProgramArgumentsParser.h src/ProgramArguments/CommandLineArgumentsParser.cpp src/ProgramArguments/CommandLineArgumentsParser.h src/ProgramArguments/ConstProgramArguments.cpp src/ProgramArguments/ConstProgramArguments.h src/Detector/EdgeDetecion/CannyEdgeDetectionStage.cpp src/Detector/EdgeDetecion/CannyEdgeDetectionStage.h src/BlockingListner.cpp src/BlockingListner.h src/Detector/Geometry/Point.h src/Detector/PreProcessing/BasicPreProcessingStage.cpp src/Detector/PreProcessing/BasicPreProcessingStage.h src/Detector/OpticDiscDetector.h src/Detector/ProcessingStage.h src/Detector/ImageProcessingStage.h src/Detector/ProcessingStageComposite.h)
set(TEST_SOURCE_FILES src/Tests/CommandLineArgumentsParserTest.cpp src/Detector/OpticDiscDetectionResult.cpp src/Detector/OpticDiscDetectionResult.h src/Tests/ProcessingStageCompositeTest.cpp)

add_executable(optic-disc-detector ${SOURCE_FILES} src/main.cpp)
target_link_libraries(optic-disc-detector ${LIBS})

add_executable(optic-disc-detector-test ${SOURCE_FILES} ${TEST_SOURCE_FILES} src/test.cpp)
target_link_libraries(optic-disc-detector-test ${LIBS})

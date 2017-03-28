
#include <opencv2/imgproc.hpp>
#include "DisplayingDecorator.h"
std::unique_ptr<CvNamedWindow> DisplayingDecorator::mWindow;

cv::Mat DisplayingDecorator::operator()(cv::Mat image) const {
    auto result = ProcessingStageDecorator<cv::Mat>::operator()(std::move(image));

    if (!mWindow) {
        mWindow = std::make_unique<CvNamedWindow>("DisplayingDecoratorWindow");
    }

    auto toDisplay = result.clone();
    if (toDisplay.type() == CV_8UC1) {
        cv::cvtColor(toDisplay, toDisplay, CV_GRAY2BGR);
    }
    cv::putText(toDisplay,
                typeid(decorated()).name(),
                cv::Point(32, toDisplay.rows),
                CV_FONT_HERSHEY_TRIPLEX,
                toDisplay.rows * 0.002,
                cv::Scalar(255, 0, 255));
    mWindow->display(toDisplay);

    return result;
}

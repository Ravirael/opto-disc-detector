#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui.hpp>
#include "DisplayingDecorator.h"

cv::Mat DisplayingDecorator::operator()(cv::Mat image) const {
    auto result = ProcessingStageDecorator<cv::Mat>::operator()(std::move(image));

    cv::namedWindow(mWindowName, CV_WINDOW_NORMAL);
    cv::imshow(mWindowName, result);
    cv::waitKey(0);
    cv::destroyWindow(mWindowName);

    return result;
}

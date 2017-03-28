#include "CvNamedWindow.h"
#include <opencv2/highgui.hpp>

CvNamedWindow::CvNamedWindow(const std::string &windowName, const unsigned int waitTime) : mWaitTime(waitTime),
                                                                                           mWindowName(windowName) {
    cv::namedWindow(mWindowName, CV_WINDOW_NORMAL);
}

void CvNamedWindow::display(const cv::Mat &mat) const {
    cv::imshow(mWindowName, mat);
    cv::waitKey(mWaitTime);
}


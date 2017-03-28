#pragma once
#include <string>
#include <opencv2/core/mat.hpp>

class CvNamedWindow {
    const unsigned mWaitTime;
    const std::string mWindowName;

public:
    CvNamedWindow(const std::string &windowName, const unsigned int waitTime = 0);
    void display(const cv::Mat &mat) const;
};



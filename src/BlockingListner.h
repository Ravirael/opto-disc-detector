#pragma once
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core/mat.hpp>

struct BlockingListner {
    std::string mWindowName{"BlockingWindow"};


    BlockingListner() {
            cv::namedWindow(mWindowName, CV_WINDOW_NORMAL);
        }

    void operator()(std::string description, const cv::Mat representation) {
        if (representation.cols <= 0 || representation.rows <= 0) return;
        std::cout << description << std::endl;
        cv::imshow(mWindowName, representation);
        cv::waitKey(0);
    }

    ~BlockingListner() {
        cv::destroyWindow(mWindowName);
    }
};


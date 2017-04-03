#include <opencv2/core.hpp>
#include "TrimBorder.h"

namespace {
    int findLeftLimit(const cv::Mat &mat) {
        for (int x = 0; x < mat.cols; ++x) {
            auto col = mat.col(x);
            if (cv::sum(col)[0] > 0) {
                return x;
            }
        }
        return mat.cols;
    }

    int findRightLimit(const cv::Mat &mat) {
        for (int x = mat.cols - 1; x > 0; --x) {
            auto col = mat.col(x);
            if (cv::sum(col)[0] > 0) {
                return x;
            }
        }
        return 0;
    }
}

cv::Mat TrimBorder::operator()(cv::Mat mat) const {
    int left = findLeftLimit(mat);
    int right = findRightLimit(mat);

    return mat(cv::Rect(left, 0, right - left, mat.rows));
}

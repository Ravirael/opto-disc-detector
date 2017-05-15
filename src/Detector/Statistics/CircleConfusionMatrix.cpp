#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include "CircleConfusionMatrix.h"

namespace {
    cv::Mat createWithCircle(Circle<int> circle, unsigned width, unsigned height) {
        cv::Mat mat(height, width, CV_8UC1, cv::Scalar(0));
        const cv::Point center(circle.center().x(), circle.center().y());
        const int radius = circle.radius();
        cv::circle(mat, center, radius, cv::Scalar(255), -1);
        return mat;
    }
}

CircleConfusionMatrix::CircleConfusionMatrix(Circle<int> real, Circle<int> detected, unsigned width, unsigned height) {
    cv::Mat realMat = createWithCircle(real, width, height);
    cv::Mat detectedMat = createWithCircle(detected, width, height);

    cv::Mat truePositiveMat;
    cv::bitwise_and(realMat, detectedMat, truePositiveMat);
    mTruePositive = cv::sum(truePositiveMat/255)[0];

    cv::Mat falsePositiveMat;
    cv::bitwise_xor(truePositiveMat, detectedMat, falsePositiveMat);
    mFalsePositive = cv::sum(falsePositiveMat/255)[0];

    cv::bitwise_not(realMat, realMat);
    cv::bitwise_not(detectedMat, detectedMat);

    cv::Mat trueNegativeMat;
    cv::bitwise_and(realMat, detectedMat, trueNegativeMat);
    mTrueNegative = cv::sum(trueNegativeMat/255)[0];

    cv::Mat falseNegativeMat;
    cv::bitwise_xor(trueNegativeMat, detectedMat, falseNegativeMat);
    mFalseNegative = cv::sum(falseNegativeMat/255)[0];
}

unsigned int CircleConfusionMatrix::truePositive() const {
    return mTruePositive;
}

unsigned int CircleConfusionMatrix::trueNegative() const {
    return mTrueNegative;
}

unsigned int CircleConfusionMatrix::falsePositive() const {
    return mFalsePositive;
}

unsigned int CircleConfusionMatrix::falseNegative() const {
    return mFalseNegative;
}

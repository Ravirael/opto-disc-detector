#pragma once
#include <boost/signals2.hpp>
#include <opencv2/core/mat.hpp>

class ProcessingSubstepNotificator {
public:
    using SlotSignature = void(std::string, const cv::Mat);
    using Signal = boost::signals2::signal<SlotSignature>;

    virtual boost::signals2::connection connect(std::function<SlotSignature> slot) = 0;
    virtual ~ProcessingSubstepNotificator() noexcept;
};



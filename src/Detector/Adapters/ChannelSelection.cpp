#include <opencv2/core.hpp>
#include "ChannelSelection.h"

ChannelSelection::ChannelSelection(std::size_t channelIndex) noexcept :
    mChannel(channelIndex) {

}

cv::Mat ChannelSelection::operator()(cv::Mat input) const {
    std::vector<cv::Mat> channels;
    cv::split(input, channels);
    return channels.at(mChannel);
}

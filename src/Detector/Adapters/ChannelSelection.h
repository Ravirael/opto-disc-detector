#pragma once


#include "../ImageProcessingStage.h"

class ChannelSelection final: public ImageProcessingStage {
    const std::size_t mChannel;

public:
    enum {
        B = 0, G = 1, R = 2
    };

    ChannelSelection(std::size_t channelIndex) noexcept;
    Result operator()(Argument arg) const override;
};



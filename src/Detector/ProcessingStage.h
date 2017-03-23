#pragma once

template <typename Argument, typename Result = Argument>
class ProcessingStage {
public:
    virtual Result operator()(Argument arg) const = 0;
    virtual ~ProcessingStage() noexcept = default;
};



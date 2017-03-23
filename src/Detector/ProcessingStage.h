#pragma once

template <typename A, typename R = A>
class ProcessingStage {
public:
    using Argument = A;
    using Result = R;
    virtual Result operator()(Argument arg) const = 0;
    virtual ~ProcessingStage() noexcept = default;
};



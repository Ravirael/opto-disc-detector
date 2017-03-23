#pragma once
#include <memory>

class DefaultStageFactory final {
public:
    template <typename T, typename ...Args>
    std::unique_ptr<T> create(Args && ... args) const {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }
};
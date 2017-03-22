#pragma once

#include "Point.h"

template <typename T>
class Circle {
    const Point<T> mCenter;
    const T mRadius;

public:
    Circle(Point<T> center, T radius) :
            mCenter(std::move(center)),
            mRadius(std::move(radius)) {
    }

    Point<T> center() const noexcept {
        return mCenter;
    }

    T radius() const noexcept {
        return mRadius;
    }

    template <typename U>
    static Circle<U> create(Point<U> center, U radius) {
        return Circle<U>(std::move(center), radius);
    }
};



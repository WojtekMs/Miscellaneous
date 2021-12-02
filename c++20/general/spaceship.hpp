#pragma once
#include <compare>

// since gcc 10
// <=> operator should return either:
// auto
// std::strong_orderding (compare every member!)
// std::weak_ordering (for example comparing string case insensitive)
// std::partial_ordering (NaN values; map values; people in family; distinguishable, but not orderable)
class Spaceship {
    int speed{};
    public:
    explicit Spaceship(int val) : speed(val) {}
    auto operator<=>(const Spaceship& rhs) const {
        if (speed < rhs.speed) {
            return -1;
        }
        if (speed > rhs.speed) {
            return 1;
        }
        return 0;
    }
};

// since gcc 10
// should be possible to make it default along with operator==()
class DefaultSpaceship {
    int speed{};
    public:
    explicit DefaultSpaceship(int val) : speed(val) {}
    auto operator<=>(const DefaultSpaceship& rhs) const = default;
};

class ProperSpaceship {
    int speed{};
    public:
    explicit ProperSpaceship(int val) : speed(val) {}
    std::strong_ordering operator<=>(const ProperSpaceship& rhs) const = default;
};

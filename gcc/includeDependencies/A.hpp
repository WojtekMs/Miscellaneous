#pragma once

#include "B.hpp"

class A {
    public:
    A() = default;
    A(const B&);
};

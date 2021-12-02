#pragma once

#include "A.hpp"

class A; //without this forward declaration it will not compile

class B {
    public:
    B() = default;
    B(const A&);
};

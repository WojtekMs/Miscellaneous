#include <iostream>

[[maybe_unused]] int empty([[maybe_unused]] int value) {
    return 1;
}

using MyValue [[maybe_unused]]  = double;

class [[maybe_unused]] InterestingClass {

};

//return value cannot be ignored
[[nodiscard]] int doNotIgnoreMe() {
    return 10;
}

int main() {
    [[maybe_unused]] int x{};
    int choice{2};
    switch (choice)
    {
        [[unlikely]] //used to optimize code
        case 0:
        empty(3);
        [[fallthrough]]; //no need for break
        case 1:
        std::cout << "hello!\n";
        break;
        [[likely]] //used to optimize code
        case 2:
        std::cout << "i am likely to be invoked!\n";
        break;
    }
    [[maybe_unused]] auto Okay = doNotIgnoreMe();
}

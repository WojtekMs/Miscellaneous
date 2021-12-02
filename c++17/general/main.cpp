#include <iostream>
#include <utility>
#include <memory>

//compilation failure inside constexpr if
// int square(int x) {
//     return x * x;
// }
constexpr int square(int x) {
    return x * x;
}

template <typename T>
auto getValue(T val) {
    if constexpr (std::is_pointer_v<T>) {
        return *val;
    } else { //without else, there is compile error: bad deduction 
    //this else clause will not be evaluted because this is template and constexpr if
        return val;
    }
}

template <typename ...Args>
auto sum(Args... args) {
    if constexpr (sizeof...(args) > 0) {
        //do something only when args are passed
        std::cout << "arguments passed!\n";
        return (args + ...);
    }
    return 0;
}

class HelloClass {

};

int main() {
    //----------------------------------------
    //constexpr if + init statement
    if (auto [key, value] = std::make_pair(3, 5); key < value) {
        std::cout << "hello with init statement if!\n";
    }
    if constexpr (5 < 7) {
        std::cout << "constexpr if!\n";
    }
    //if square is not constexpr will fail to compile
    if constexpr (square(5) > 10) {
        std::cout << "constexpr if with function call!\n";
    }
    if constexpr (constexpr int x = 3; square(x) < 10) {
        std::cout << "variable is constexpr, hence this works!\n";
    }
    int value{5};
    int* pointer{&value};
    std::cout << getValue(pointer) << '\n';
    std::cout << getValue(value) << '\n';
    std::cout << sum() << '\n';
    std::cout << sum(5, 3, 8) << '\n';

    auto hello = std::make_unique<HelloClass>(new HelloClass{});
    std::unique_ptr<HelloClass> hello2{new HelloClass{}};
}

#include <iostream>

int main() {
//     // int value = 16;
//     // value <<= 2;
//     // std::cout << value;
//     std::cout << "ABC"[1]; //displays B
//     std::cout << "ABC" + 1; //displays BC
    int* a = reinterpret_cast<int*>(&a);
    std::cout << a << '\n';
    std::cout << &a << '\n';
    std::cout << *a << '\n';
}

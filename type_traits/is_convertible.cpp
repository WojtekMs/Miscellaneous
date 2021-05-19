#include <type_traits>
#include <string>
#include <iostream>
#include <iomanip>
int main() {
    std::cout << std::boolalpha;
    const char text[] = "boby";
    std::cout << std::is_convertible_v<std::string, decltype(text)> << '\n';
    std::cout << std::is_convertible_v<std::string, decltype(const_cast<char* >(text))> << '\n';
}

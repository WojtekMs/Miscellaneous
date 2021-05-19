#include <iostream>
#include <string>

int main() {
    std::string output{};
    char non_terminating_null[] = {'h', 'e', 'l', 'l', 'o'};
    char c_str[] = {"world"};
    output += std::string(c_str, c_str + 0);
    std::cout << output;
    std::cout << output.size();

}

#include <iostream>
#include <string>
#include <ranges>
#include <algorithm>

std::string to_octal(int decimal) {
    std::string octal{};
    while(decimal) {
        octal.push_back((decimal % 8) + '0');
        decimal /= 8;
    }
    std::reverse(octal.begin(), octal.end());
    return octal;
}

namespace r{
std::string to_octal(int decimal) {
    std::string octal{};
    while(decimal) {
        octal.push_back((decimal % 8) + '0');
        decimal /= 8;
    }
    std::ranges::reverse(octal);
    return octal;
}

}

int main(int argc, const char** argv) {
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " decimal_number\n";
        return EXIT_FAILURE;
    }
    const int decimal = atoi(argv[1]);
    std::cout << to_octal(decimal) << "\n";
    std::cout << r::to_octal(decimal) << "\n";
    return EXIT_SUCCESS;
}

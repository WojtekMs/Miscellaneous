#include <iostream>
#include <string>
#include <algorithm>
#include <ranges>


std::string to_binary(const int decimal) {
    constexpr int bits = sizeof(decimal) * 8;
    std::string binary{};
    for (int i = bits - 1; i >= 0; i--) {
        const auto bit = static_cast<bool>(decimal & (1 << i));
        binary.push_back(bit + '0');
    }
    return binary;
}

namespace r{
std::string to_binary(const int decimal) {
    constexpr int bits = sizeof(decimal) * 8;
    std::string binary{};
    for (int i : std::views::iota(0, bits) | std::views::reverse) {
        const auto bit = static_cast<bool>(decimal & (1 << i));
        binary.push_back((bit + '0'));
    }
    return binary;
}

}

std::string to_binary2(int decimal) {
    std::string result{};
    while (decimal) {
        result.push_back((decimal & 1) + '0');
        decimal /= 2;
    }
    std::ranges::reverse(result);
    return result;
}

int main(int argc, const char** argv) {
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " decimal_number\n";
        return EXIT_FAILURE;
    }
    const int decimal = atoi(argv[1]);
    std::cout << to_binary(decimal) << "\n";
    std::cout << r::to_binary(decimal) << "\n";
    std::cout << to_binary2(decimal) << "\n";
    return EXIT_SUCCESS;
}

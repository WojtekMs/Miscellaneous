#include <iostream>
#include <string>
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

int main(int argc, const char** argv) {
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " decimal_number\n";
        return EXIT_FAILURE;
    }
    const int decimal = atoi(argv[1]);
    std::cout << r::to_binary(decimal) << "\n";
    return EXIT_SUCCESS;
}

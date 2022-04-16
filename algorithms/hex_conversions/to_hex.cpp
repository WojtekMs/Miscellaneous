#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>

std::string to_hex(int decimal)
{
  std::string hex{};
  // can be replaced with just a std::array
  std::unordered_map<int, char> decimal_hex{
      {0, '0'},
      {1, '1'},
      {2, '2'},
      {3, '3'},
      {4, '4'},
      {5, '5'},
      {6, '6'},
      {7, '7'},
      {8, '8'},
      {9, '9'},
      {10, 'A'},
      {11, 'B'},
      {12, 'C'},
      {13, 'D'},
      {14, 'E'},
      {15, 'F'},
  };
  while (decimal) {
    hex.push_back(decimal_hex[decimal % 16]);
    decimal /= 16;
  }
  std::reverse(hex.begin(), hex.end());
  return hex;
}

namespace a
{
std::string to_hex(int decimal)
{
  std::string hex{};
  constexpr std::array<char, 16> decimal_hex{
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  while (decimal) {
    hex.push_back(decimal_hex[decimal % 16]);
    decimal /= 16;
  }
  std::reverse(hex.begin(), hex.end());
  return hex;
}
}  // namespace a

int main(int argc, const char** argv)
{
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " decimal_number\n";
    return EXIT_FAILURE;
  }
  const int decimal = atoi(argv[1]);
  std::cout << to_hex(decimal) << "\n";
  std::cout << a::to_hex(decimal) << "\n";
  return EXIT_SUCCESS;
}

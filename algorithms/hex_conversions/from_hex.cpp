#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>

int from_hex(const std::string& hex)
{
  int decimal{0};
  int multiplier{1};
  std::unordered_map<char, int> hex_decimal{
      {'0', 0},
      {'1', 1},
      {'2', 2},
      {'3', 3},
      {'4', 4},
      {'5', 5},
      {'6', 6},
      {'7', 7},
      {'8', 8},
      {'9', 9},
      {'A', 10},
      {'B', 11},
      {'C', 12},
      {'D', 13},
      {'E', 14},
      {'F', 15},
  };
  for (int i = hex.size() - 1; i >= 0; --i) {
    if (hex[i] != '0') {
      decimal += hex_decimal[hex[i]] * multiplier;
    }
    multiplier *= 16;
  }
  return decimal;
}

namespace r
{
int from_hex(const std::string& octal)
{
  int decimal{0};
  int multiplier{1};
  std::unordered_map<char, int> hex_decimal{
      {'0', 0},
      {'1', 1},
      {'2', 2},
      {'3', 3},
      {'4', 4},
      {'5', 5},
      {'6', 6},
      {'7', 7},
      {'8', 8},
      {'9', 9},
      {'A', 10},
      {'B', 11},
      {'C', 12},
      {'D', 13},
      {'E', 14},
      {'F', 15},
  };
  for (const auto bit : std::views::reverse(octal)) {
    if (bit != '0') {
      decimal += hex_decimal[bit] * multiplier;
    }
    multiplier *= 16;
  }
  return decimal;
}
}  // namespace r

int main(int argc, const char** argv)
{
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " hex_number\n";
    return EXIT_FAILURE;
  }
  std::cout << from_hex(argv[1]) << "\n";
  std::cout << r::from_hex(argv[1]) << "\n";
  return EXIT_SUCCESS;
}

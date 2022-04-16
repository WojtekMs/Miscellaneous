#include <bitset>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>

int from_binary(const std::string& binary)
{
  int decimal{0};
  int multiplier{1};
  for (int i = binary.size() - 1; i >= 0; --i) {
    if (binary[i] == '1') {
      decimal += multiplier;
    }
    multiplier *= 2;
  }
  return decimal;
}

namespace r
{
int from_binary(const std::string& binary)
{
  int decimal{0};
  int multiplier{1};
  for (const auto bit : std::views::reverse(binary)) {
    if (bit == '1') {
      decimal += multiplier;
    }
    multiplier *= 2;
  }
  //   in case you would like to access index
  //   for (int i : std::views::iota(0, static_cast<int>(binary.size())) | std::views::reverse) {
  //   }
  return decimal;
}
}  // namespace r

namespace sv
{
int from_binary(std::string_view binary)
{
  int multiplier{1};
  int decimal{0};
  for (const auto bit : std::views::reverse(binary)) {
    if (bit == '1') {
      decimal += multiplier;
    }
    multiplier *= 2;
  }
  return decimal;
}

}  // namespace sv

int main(int argc, const char** argv)
{
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " binary_number\n";
    return EXIT_FAILURE;
  }
  std::cout << from_binary(argv[1]) << "\n";
  std::cout << r::from_binary(argv[1]) << "\n";
  std::cout << sv::from_binary(argv[1]) << "\n";
  return EXIT_SUCCESS;
}

#include <iostream>
#include <ranges>
#include <string>

int from_octal(const std::string& octal)
{
  int decimal{0};
  int multiplier{1};
  for (int i = octal.size() - 1; i >= 0; --i) {
    if (octal[i] != '0') {
      decimal += (octal[i] - '0') * multiplier;
    }
    multiplier *= 8;
  }
  return decimal;
}

namespace r
{
int from_octal(const std::string& octal)
{
  int decimal{0};
  int multiplier{1};
  for (const auto bit : std::views::reverse(octal)) {
    if (bit != '0') {
      decimal += (bit - '0') * multiplier;
    }
    multiplier *= 8;
  }
  return decimal;
}
}  // namespace r

int main(int argc, const char** argv)
{
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " octal_number\n";
    return EXIT_FAILURE;
  }
  std::cout << from_octal(argv[1]) << "\n";
  std::cout << r::from_octal(argv[1]) << "\n";
  return EXIT_SUCCESS;
}

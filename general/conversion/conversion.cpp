#include <iostream>
#include <string>

int main()
{
  for (int i = 0; i < 15; i++) {
    constexpr int VALUE = 6;
    std::string str{"321"};
    int difference = VALUE - (static_cast<int>(str.size()) + 1);
    std::cout << difference << '\n';
  }
}

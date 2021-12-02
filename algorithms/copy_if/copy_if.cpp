#include <algorithm>
#include <iostream>
#include <string>

int main()
{
  std::string text{"k&*(AJA*)(K"};
  std::string pure_text;
  pure_text.reserve(text.size());
  std::cout << pure_text << "\n";

  std::copy_if(
      text.begin(), text.end(), std::back_inserter(pure_text), [](unsigned char letter) { return isalnum(letter); });
  std::cout << pure_text << "\n";

  pure_text.shrink_to_fit();
  std::cout << pure_text << "\n";
}

#include <iostream>
#include <vector>

class Verbose
{
 public:
  Verbose() = default;
  Verbose(const Verbose&) { std::cout << "copy constructor\n"; }
//   Verbose(Verbose&&) { std::cout << "move constructor\n"; }
};

int main()
{
  std::vector<Verbose> v;
  v.emplace_back(Verbose{});
}

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::cout << *std::rotate(begin(v) + 1, begin(v) + 4, begin(v) + 5);
  std::cout << std::endl;
  std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  std::cout << *std::rotate(begin(v) + 1, begin(v) + 4, begin(v) + 6);
  std::cout << std::endl;
  std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
}

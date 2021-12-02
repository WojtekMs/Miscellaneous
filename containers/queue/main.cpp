#include <deque>
#include <iostream>
#include <list>
#include <queue>
int main()
{
  std::queue<int, std::list<int>> queue{{3, 6, 2, 8, 1}};  // the order of the elements is preserved
  std::cout << queue.front() << '\n'; // 3
  std::cout << queue.back() << '\n'; // 1
  queue.push(10);
  std::cout << queue.front() << '\n';  // 3
  std::cout << queue.back() << '\n';   // 10
  queue.pop();
  std::cout << queue.front() << '\n';  // 6
  std::cout << queue.back() << '\n';   // 10
  std::cout << "\n----------------------\n";
  for (size_t i = 0, delim = queue.size(); i < delim; ++i) {
      std::cout << queue.front() << ' ';
      queue.pop();
  }
}

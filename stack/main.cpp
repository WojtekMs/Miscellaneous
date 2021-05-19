#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int main()
{
  std::stack<int, std::vector<int>> stack{{1, 5, 3, 8, 2}};
  std::cout << stack.top() << '\n';
//   s.pop();
  std::cout << stack.top() << '\n';
//   s.push(10);
  std::cout << stack.top() << '\n';
}

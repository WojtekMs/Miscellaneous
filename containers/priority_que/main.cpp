#include <iostream>
#include <queue>

void test1() {
  std::priority_queue<int, std::deque<int>, std::greater<int>> pqueue{std::greater<int>(), {5, 3, 1, 8, 10}};  
                                                                        // the elements will be sorted instantly
                                                                        // the order is now ascending 1, 3, 5, 8, 10
  std::cout << pqueue.top() << '\n';  //1
  pqueue.pop();
  std::cout << pqueue.top() << '\n'; //3
  pqueue.pop();
  std::cout << pqueue.top() << '\n'; //5
}

void test2() {
  std::vector<int> vec{7, 8, 9, 12, 1, 3, 17, 22};
  std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue{vec.begin(), vec.end()};
  pqueue.pop();
  pqueue.pop();
  for (auto elem : vec) {
    std::cout << elem << ", ";
  }
}

int main()
{
  // test1();
  test2();
}

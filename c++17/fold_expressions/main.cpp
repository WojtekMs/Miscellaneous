#include <iostream>
#include <utility>
#include <vector>

template <typename... Args>
double sum(Args... args)
{
  return (0 + ... + args);
}

template <typename... Args>
double sum2(Args... args)
{
  return (args + ...);
}

template <typename T>
void print(T value)
{
  std::cout << value << ", ";
}

void print() {}

template <typename... Args>
void print(Args... args)
{
  // print(head);
  // print(args...);
  (std::cout << ... << args);
}


void print(const std::vector<int>& vec)
{
  for (auto elem : vec) {
    std::cout << elem << ", ";
  }
  std::cout << '\n';
}

template <typename ValueType, typename ...Values>
void push_back_many(std::vector<ValueType>& vec, Values... values) {
    (vec.push_back(values) , ...);
}

template <typename ...Values>
void print_many(Values... values) {
    ((std::cout << values << ", ") , ... );
    std::cout << '\n';
}

template <typename ...Values>
long double factorial(Values... values) {
    return (1 * ... * values);
}

template <typename ...Values>
long double factorial2(Values... values) {
    return (values * ...);
}

int main()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::string dash(50, '-');
  std::cout << dash << '\n';
  std::cout << sum2(3, 2.0, 2.5, 3.5) << '\n';
  std::cout << dash << '\n';
  print("hi", 2, 3.0);
  std::cout << dash << '\n';

  vec.push_back(5), vec.push_back(7), vec.push_back(9), vec.push_back(10);
  print(vec);
  push_back_many(vec, 5, 3, 7, 10, 11.0);
  print(vec);
  std::cout << dash << '\n';
  print_many(5, 7.5, "ab", "ba");
  std::cout << dash << '\n';
  std::cout << factorial(1, 2, 3, 4, 5, 6) << '\n';
  std::cout << factorial() << '\n';
  factorial2(1);
}

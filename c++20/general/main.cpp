#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "spaceship.hpp"
#include <utility>
#include <tuple>
#include <charconv> 

std::string operator ""_s(const char* sequence, size_t size) {
  return std::string(sequence);
}
void print(const std::vector<int>& vec)
{
  for (auto elem : vec) {
    std::cout << elem << ", ";
  }
  std::cout << '\n';
}

//--------------------------------------------------------------------------------
//pack exspansion in lambda capture
template <typename ...Values>
double sum(Values... values) {
  auto packExpansionInLambda = [&values...](){
    return (0 + ... + values);
  };
  
  return packExpansionInLambda();
}

//--------------------------------------------------------------------------------
//abbreviated function templates
auto sum(auto lhs, auto rhs) {
  return lhs + rhs;
}

//can be specialized
template<>
auto sum<int*, double*>(int* lhs, double* rhs) {
  return *lhs + *rhs;
}

//--------------------------------------------------------------------------------
// since gcc 11
// consteval int immediateFunction() {
//   return 10;
// }

//--------------------------------------------------------------------------------
// since gcc 10
// constinit value = func(); //will give error if func does not return value with static initalization
//[zero initalization, constant initialization: globals, static variabales, references]

int main()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  std::string dash(50, '-');

  //--------------------------------------------------------------------------------
  // init statement in range-for
  for (int index = 0; auto elem : vec) {
    std::cout << index++ << ", " << elem << '\n';
  }
  std::cout << dash << '\n';

  //--------------------------------------------------------------------------------
  // pack expansion in lambda
  std::cout << sum(3, 5.0, 2.0) << '\n';
  std::cout << dash << '\n';

  //--------------------------------------------------------------------------------
  //aggregate initialization; designated initalizations
  //aggregate is POD; array; union [cannot have any c-stors, virtual f-ctions]
  //order of designated initialization is important! 
  // must match the order of variables in aggregate
  struct A { int a; int b; int c; int d;};
  A a{.a = 5, .c = 7, .d = 3};
  A a2{.a = 5};
  A a3{.c = 7, .d = 3};
  A a4{.b = 7};
  //in union, you can only assign value to one member
  //it becomes the active one after assignment
  union un
  {
    int val;
    double anotherVal;
  };
  un b{};
  un b2{.anotherVal = 5.0};
  un b3{.val = 3};
  
  // not supported yet, but is in the standard!
  // int tab[5]{[0] = 1, [4] = 3};
  std::cout << dash << '\n';

  //--------------------------------------------------------------------------------
  //abbreviated function templates
  using namespace std::string_literals;
  std::cout << sum("hi"_s, "hello"_s) << '\n';
  std::cout << sum("hi"s, "hello"s) << '\n';
  std::cout << sum(1, 2) << '\n';
  std::cout << dash << '\n';

  //--------------------------------------------------------------------------------
  //operator new can deduce the size of array
  // gcc 11
  // auto array = new int[]{5, 3, 2, 1};
  auto value = new auto(5);
  auto character = new auto('c');

  //--------------------------------------------------------------------------------
  // Spaceship operator [gcc 10]
  //it generates regular comparison operators: <, >, <=, >=
  Spaceship objA{3};
  Spaceship objB{5};
  if ((objA <=> objB) < 0) {
    std::cout << "it's true, A is slower than B \n";
  }
  if (objA >= objB) {
    std::cout << "false";
  }
  DefaultSpaceship faster{5};
  DefaultSpaceship slower{3};
  if ((slower <=> faster) < 0) {
    std::cout << "slower is slower; default spaceship works!\n";
  }
  ProperSpaceship shipA{10};
  ProperSpaceship shipB{20};
  if ((shipA <=> shipB) == std::strong_ordering::less) {
    std::cout << "shipA is slower than shipB!\n";
  }
  if (shipA < shipB) {
    std::cout << "shipA is slower!\n";
  }

  //--------------------------------------------------------------------------------
  //<charconv> good for JSON/XML parsing
  //very fast solution; noexcept!
  //if no pattern is found it returns errorCode such that errorCode == std::errc::invalid_argument
  //if pattern is found errorCode == std::errc()
  char text[]{"457x"};
  int result{};
  auto [textResult, errorCode] = std::from_chars(std::begin(text), std::end(text), result);
  std::cout << textResult << '\n';
  std::cout << result << '\n';

  //--------------------------------------------------------------------------------
  // Modules
  // in gcc 11 only partial implementation

  //--------------------------------------------------------------------------------
  // Coroutines
  // since gcc 10

  //--------------------------------------------------------------------------------
  // Concepts
  // since gcc 10



}

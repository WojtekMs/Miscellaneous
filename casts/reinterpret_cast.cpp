#include <iostream>

struct A {
  int val{1};
  char val2{'a'};
  double val3{1.0};
};

struct B : A {
  int val{2};
};

struct C {
  int val1{3};
  double val2{3.0};
};

int main()
{
  A objectA;
  B objectB;
  C objectC;
  A* a = &objectA;
  std::cout << a->val << "\n";
  a = &objectB;
  std::cout << a->val << "\n";
//   no implicit conversion
//   no static_cast conversion
//   we receive addres of object C and we try to read it like object A
//   values in memory pointed by address are allocated according to struct C layout
//   when we try to read these values like they belong to A we read invalid values
//   struct A and struct C would require the same memory layout for this to be safe
  a = reinterpret_cast<A*>(&objectC);
  std::cout << static_cast<int>(a->val2) << "\n";
  std::cout << a->val3 << "\n";

  return 0;
}

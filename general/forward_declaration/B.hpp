#pragma once
#include <memory>
#include <string>

// this causes compilation errors for files that include B and do not include A
class A;
class B
{
  std::unique_ptr<A> ptr;

 public:
  std::string print() const;
  ~B() = default;
};

#include "B.hpp"

#include "A.hpp"

std::string B::print() const
{
  return ptr->print();
}


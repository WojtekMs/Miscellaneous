#include <memory>

class A;
class B
{
 public:
  ~B();
  std::unique_ptr<A> a;
};

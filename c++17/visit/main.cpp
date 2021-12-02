#include <functional>
#include <iostream>
#include <map>
#include <variant>
#include <vector>

struct printVariant {
  void operator()(int val) { std::cout << "int " << val; };
  void operator()(double val) { std::cout << "double " << val; };
  void operator()(std::string text) { std::cout << "text " << text; };
};

struct performOperation {
  double first;
  double second;
  performOperation() = default;
  performOperation(double a, double b) : first(a), second(b) {}
  void operator()(std::function<void(int)> f) { f(first); }
  void operator()(std::function<double(double)> f) const { f(3.5); }
  //   void operator()(std::function<int(int, int)> f) const { f(2, 3); }
};

void funct(const std::function<double(double)>& f)
{
  double value = f(5);
  std::cout << value << '\n';
}

struct functor {
//   double value;
//   functor(double val) : value(val) {}
  double operator()(double something)
  {
    std::cout << "functor returning double with parameter " << something << '\n';
    return something;
  }
};

double regular_function(double value) {
    std::cout << "regular function with parameter " << value << '\n';
    return value;
}

int main()
{
  //   std::variant<std::function<void(int)>, std::function<double(double)>> var;
  //   std::variant<std::function<int(int, int)>, std::function<double(double)>> mathOps;
  //   std::vector<decltype(var)> vec{
  //       std::function<void(int)>([](int a) { std::cout << "void function with one paramater " << a << '\n'; }),
  //       std::function<double(double)>([](double a) {
  //         std::cout << "non void function with one paramater " << a << '\n';
  //         return a;
  //       })};
  //   std::map<char, decltype(mathOps)> operations{
  //       {'+', std::function<int(int, int)>([](int lhs, int rhs) { return lhs + rhs; })},
  //       {'!', std::function<double(double)>([](int lhs) { return lhs; })},
  //   };

  // std::visit(performOperation(), vec[1]);
  //   std::visit(performOperation(), operations.at('+'));

//   funct([](double first) { return first; });
//   funct(functor());
//   funct(regular_function);
    std::string operators{"\\+"};
    std::cout << operators;
}

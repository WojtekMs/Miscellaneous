#include <functional>
#include <iostream>

using Sum = std::function<int(int, int)>;

auto sum = [](int lhs, int rhs){ return lhs + rhs; };
auto sumWith5 = [x{5}](int lhs, int rhs){ return x + lhs + rhs; };
//o co chodzi?
//lambda bez niczego na liscie przechwytujacej jest kompilowana do zwyklej f-cji, 
//zatem standardowy C wskaznik na f-cje przyjmie taka lambde
//lambda ktora ma cos na liscie przechwytujacej jest kompilowana do klasy,
//zatem standardowy C wskaznik na f-cje nie przyjmie juz takiej lambdy,
//musimy uzywac wrapera std::function <- ktory przyjmuje zwykle f-cji, funktory i lambdy
class A {
    public:
    Sum sum_{sum};
    Sum sumWith5_{sumWith5};
    Sum getSum() { return sum_; };
    Sum getSumWith5() { return sumWith5_; }
    
};

int iUseSum(int (*sum)(int, int), int lhs, int rhs) {
    return sum(lhs, rhs);
}

int iUseSumProperly(std::function<int(int, int)> sum, int lhs, int rhs) {
    return sum(lhs, rhs);
}

int main() {
    A a;
    auto sum = a.getSum();
    std::cout << sum(2, 3) << '\n';
    auto sumWith5 = a.getSumWith5();
    std::cout << sumWith5(3, 5) << '\n';
    // std::cout << iUseSum(sum, 2, 3) << '\n';
    std::cout << iUseSumProperly(sum, 2, 3) << '\n';
    // std::cout << a.getSum()(5, 3) << '\n';
}

#include <memory>
#include <iostream>
int main() {
    int defaultVal{5};
    std::shared_ptr<int> shared{new int{defaultVal}};
    std::weak_ptr<int> weak{shared};
    std::cout << weak.use_count() << '\n';
    shared.reset();
    std::cout << shared.use_count() << '\n';
    std::cout << weak.use_count() << '\n';

}

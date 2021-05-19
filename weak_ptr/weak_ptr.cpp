#include <iostream>
#include <memory>

int main() {
    auto shared = std::make_shared<int>(5);
    std::weak_ptr<int> weak(shared);
    std::weak_ptr<int> emptyWeak;
    weak = emptyWeak;
    std::cout << weak.expired() << '\n';
    try {
        std::shared_ptr<int> sharedFromEmptyWeak(emptyWeak);
    }
    catch (std::bad_weak_ptr& exception) {
        std::cout << exception.what() << '\n';
    }
}

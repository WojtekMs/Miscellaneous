#include <atomic>
#include <iostream>

int main() {
    std::atomic_size_t count = 0;
    count--;
    std::cout << count;
}

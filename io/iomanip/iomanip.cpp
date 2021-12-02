#include <iostream>
#include <iomanip>

int main() {
    std::string dash(60, '-');
    for (int i = 0; i < 10; ++i) {
    std::cout << "Type: " << std::setw(10) << i << " ";
    std::cout << "Amount: " << std::setw(10) << 2*i << " ";
    std::cout << "Price: " << std::setw(10) << 3*i + 1 << "\n";
    std::cout << dash << "\n";
    }
}

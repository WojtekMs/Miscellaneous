#include <iostream>
#include <limits>

int main() {
    unsigned int modulo{std::numeric_limits<unsigned int>::max()};
    int non_modulo{std::numeric_limits<int>::max()};

    std::cout << "Unsigned int max: " << modulo << "\n";
    std::cout << "Signed int max: " << non_modulo << "\n\n";

    std::cout << modulo << " + " << 10 << " = " << modulo + 10 << " (modulo wraparound - defined)\n";
    std::cout << non_modulo << " + " << 10 << " = " << non_modulo + 10 << " (overflow - undefined)\n";

}

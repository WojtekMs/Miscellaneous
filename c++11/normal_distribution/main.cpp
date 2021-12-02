#include <iostream>
#include <random>

double random_value_normal_distrib(double mean_value, double deviation_range) {
    std::random_device rd{};
    // https://en.cppreference.com/w/cpp/numeric/random/random_device
    // MinGW bug - deterministic results
    std::mt19937 gen{rd()};
    std::normal_distribution<> d{mean_value, deviation_range};
    return d(gen);
}

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << "random value 1 sigma: " << random_value_normal_distrib(20.0, 1.0) << "\n";

    }
    for (int i = 0; i < 10; i++) {
        std::cout << "random value 2 sigma: " << random_value_normal_distrib(20.0, 2.0) << "\n";

    }
}

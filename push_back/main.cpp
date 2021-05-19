#include <iostream>
#include <vector>

void print(const std::vector<int>& vec) {
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec1 {2, 3, 4, 5};
    std::vector<int> vec2 {1, 5, 9, 10};
    vec1.push_back(vec2[2]);
    print(vec1);
    
}

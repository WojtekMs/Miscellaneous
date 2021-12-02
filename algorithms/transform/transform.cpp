#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

void print(std::vector<int>& vec) {
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 1, 1, 1, 1}; //i think its UB when the ranges are not equal, 
                                                                    // or at least the first range is larger than second range
    std::list<int> list {10, 20, 30 , 40 , 50, 60, 70, 80, 90};
    std::transform(begin(vec),
                   end(vec),
                   begin(list),
                   begin(vec),
                   [](auto first, auto second) {
                       return first + second;
                   });
    print(vec);

    return 0;
}

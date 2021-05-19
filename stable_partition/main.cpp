#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
    std::stable_partition(begin(v), end(v), [](auto elem){
        return elem % 2 == 0;
    });
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    
}

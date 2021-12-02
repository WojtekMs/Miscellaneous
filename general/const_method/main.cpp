#include <iostream>
#include <vector>


class ConstMethodTest {
    std::vector<int> vec;

    public:
    const std::vector<int>& getVec();
};

int main() {
    ConstMethodTest test;
    test.getVec().push_back(5);
    
}

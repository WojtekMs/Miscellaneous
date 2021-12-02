#include <iostream>

class LayoutTest {
    public:
    int val;
    // unsigned long val3;
    private:
    unsigned long val2;
    // unsigned long val3;
};

int main() {
    LayoutTest object;

    std::cout << "int: " << sizeof(int) << '\n';   
    std::cout << "unsigned long: " << sizeof(unsigned long) << '\n';   

    std::cout << "class size: " << sizeof(LayoutTest) << '\n';    
    std::cout << "object size: " << sizeof(object) << '\n';

    std::cout << "padding size: " << sizeof(object) - (sizeof(int) + sizeof(unsigned long)) << '\n';
    
}

#include <iostream>

class DestructorTest {
    public:
    ~DestructorTest() {
        std::cout << "destructor\n";
    }
};

int main() {
    DestructorTest dt;
    dt.~DestructorTest(); //we are calling destructor explicitly
    // it will be called also by the compiler - when the variable goes out of the scope
}

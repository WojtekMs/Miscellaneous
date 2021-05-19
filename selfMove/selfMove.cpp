#include <utility>
#include <iostream>

class selfMoveTest {
    public:
    int* int_{nullptr};
    double* double_{nullptr};
    selfMoveTest() = default;
    selfMoveTest(int*, double*) noexcept;
    selfMoveTest& operator=(selfMoveTest&&) noexcept;
};

selfMoveTest::selfMoveTest(int* first, double* second) noexcept
:int_(first), double_(second) {

}

selfMoveTest& selfMoveTest::operator=(selfMoveTest&& rhs) noexcept {
    int_ = rhs.int_;
    double_ = rhs.double_;
    rhs.int_ = nullptr;
    rhs.double_ = nullptr;
    return *this;
}

int main() {
    int a{5};
    double b{5.2};
    selfMoveTest cut(&a, &b);
    selfMoveTest cut2;
    cut = std::move(cut);
    selfMoveTest cut3;
    if(cut.double_ == nullptr) {
        std::cout << "this is error\n";
    }
}

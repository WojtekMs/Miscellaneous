#include <utility>

class Reference{
    int& a_;
    public:
    Reference(int& a): a_(a) {

    }
    Reference(const Reference&) = default;
    Reference(Reference&&) = default;
};

void take(int&&) {

}

template <typename T>
void f(const T&) {
    return;
}

int main() {
    int b{3};
    int alpha{5};
    Reference ref(alpha);
    Reference ref2(ref);

    const int& reference = b;
    int c{7};
    take(std::move(b));
    take(std::move(c));

    f(5);

}

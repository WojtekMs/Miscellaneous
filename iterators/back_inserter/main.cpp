#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

class Cargo {
public:
    virtual int getPrice() = 0;
    virtual ~Cargo(){};
};

class Item : public Cargo {
    int getPrice() override { return 1; };
};

struct object {
    int value;
    explicit object(int v = 5)
        : value(v){};
    void setValue(int val) { value = val; };
    int getValue() { return value; };
};

main() {
    // Cargo* c_ptr = nullptr;
    // std::shared_ptr<Cargo> c_sptr = std::shared_ptr<Cargo>(c_ptr);

    object objA;
    std::shared_ptr<object> s_ptr = std::make_shared<object>(objA);
    s_ptr->setValue(10);
    std::cout << "objA val: " << objA.getValue() << "\n";
    objA.setValue(50);
    std::cout << "objA val: " << objA.getValue() << "\n";
    // std::shared_ptr<object> s_ptr2(&objA);
    // std::cout << "s_ptr2 val: " << s_ptr2->getValue() << "\n";
    // s_ptr2->setValue(100);
    std::cout << "objA val: " << objA.getValue() << "\n";
    std::cout << "s_ptr val: " << s_ptr->getValue() << "\n";
    // std::cout << "s_ptr2 val: " << s_ptr2->getValue() << "\n";
}

// void printVector(const std::vector<int>& vec) {
//     for (auto val : vec) {
//         std::cout << val << ", ";
//     }
//     std::cout << "\n";
// }

// bool is_palindrome(const std::string& text) {
//     std::string pure_text;
//     pure_text.reserve(text.size());
//     std::transform(text.begin(), text.end(),   std::back_inserter(pure_text),
//                    [](unsigned char letter) {
//                        if (isalnum(letter)) {
//                            return tolower(letter);
//                        } else {
//                            continue;
//                        }
//                    });
// pure_text.shrink_to_fit();
// std::cout << "text: " << text << "\n";
// std::cout << "pure text: " << pure_text << "\n";
// std::cout << "pure text size: " << pure_text.size() << "\n";
// }

// int main() {
//   is_palindrome("K&(*&A J     AK");
// }

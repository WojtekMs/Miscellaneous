#include <iostream>
#include <string>

int main() {
    int value{100};
    int desired_str_value_size{6};
    std::string str_value = std::to_string(value);
    if (str_value.size() > desired_str_value_size) {
        //error, too big message
    }
    std::cout << str_value << '\n';
    int zero_padding = desired_str_value_size - str_value.size();
    for (int i = 0; i < zero_padding; ++i) {
        str_value.insert(str_value.begin(), '0');
    }
    std::cout << str_value << '\n';

}

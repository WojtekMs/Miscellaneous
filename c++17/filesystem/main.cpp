#include <filesystem>
#include <iostream>

bool starts_with(const std::filesystem::path& p, const std::string& prefix) {
    return  p.string().rfind(prefix, 0) == 0;
}

int main() {
    std::filesystem::path base{"/home/wojtek/networking/data"};
    std::string input{};
    std::cout << "enter desired path: ";
    std::cin >> input;
    std::cout << "no sanitization: " << base / input << "\n";
    const auto sanitized_path = (base / input).lexically_normal();
    std::cout << "lexically normal: " << sanitized_path << "\n";
    std::cout << "is given path child of base path: " << std::boolalpha << starts_with(sanitized_path, base) << "\n";
}

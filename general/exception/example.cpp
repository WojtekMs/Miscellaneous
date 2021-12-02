#include <iostream>
#include <stdexcept>

class NewException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Hello!\n";
    }
};

class DupaException : public std::exception {
    public:
    const char* what() const noexcept override {
        return "Dupa!\n";
    }
};

class GreenException : public NewException, public DupaException {
    public:
    const char* what() const noexcept override {
        return "Strange exception!\n";
    }
};
int main() {
    try {
        throw GreenException{};
    }
    catch (DupaException& e) {
        std::cout << e.what() << '\n';
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    // catch (...) {
    //     std::cout << "Last catch!\n";
    // }
}

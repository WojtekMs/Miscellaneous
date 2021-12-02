#include <string>
#include <iostream>
#include <cstring>

int main() {
    char c_string[] = "Hello World!";
    //CAREFUL! non null terminated c_string
    char c_string_non_null[] = {'h', 'e', 'l', 'l', 'o'};
    std::string testing(c_string);
    std::string testing2(c_string, c_string + 3);
    //ERRORS!
    // std::string testing3(c_string_non_null);
    char c_string2[] = {'h', 'e', 'l', '\0', '\0'};
    char c_string3[] = {'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'};
    std::string testing4{};
    testing4 += std::string(c_string2, c_string2 + 3);
    //WARNING!: you are creating string made of all 10 characters, including the null terminating character!
    //if you want to have a well-formed string you must remember not to include the last character ('\0)!
    testing4 += std::string(c_string3, c_string3 + 10);
    std::string testing5{c_string3};

    //When using range-based string constructor it will work fine, when c_string doesnt include '\0' at the end
    //but you must exactly know how many characters to include: and you cannot rely on strlen because c_str doesnt include '\0' at the end
    //this can be used only when you know how many characters to take
    std::string testing6(c_string_non_null, c_string_non_null + 5);

    

    std::cout << "string created with '\\0': " << testing << '\n';
    std::cout << "string created with '\\0': " << testing.size() << '\n';
    std::cout << "string created with '\\0': " << testing.c_str() << '\n';
    std::cout << "string created with '\\0': " << std::strlen(testing.c_str()) << '\n';

    std::cout << "string created without '\\0': " << testing2 << '\n';
    std::cout << "string created without '\\0': " << testing2.size() << '\n';
    std::cout << "string created without '\\0': " << testing2.c_str() << '\n';
    std::cout << "string created without '\\0': " << std::strlen(testing2.c_str()) << '\n';

    // ERRORS!
    // std::cout << "string2 created without '\\0': " << testing3 << '\n';
    // std::cout << "string2 created without '\\0': " << testing3.size() << '\n';
    // std::cout << "string2 created without '\\0': " << testing3.c_str() << '\n';
    // std::cout << "string2 created without '\\0': " << std::strlen(testing3.c_str()) << '\n';


    std::cout << "string created by concat without '\\0' and with '\\0': " << testing4 << '\n';
    std::cout << "string created by concat without '\\0' and with '\\0': " << testing4.size() << '\n';
    std::cout << "string last element: " << testing4.back();
    if (testing4.back() == '\0') {
        std::cout << "string last element is '\\0'!\n"; 
    }
    std::cout << "string created by concat without '\\0' and with '\\0': " << testing4.c_str() << '\n';
    std::cout << "string created by concat without '\\0' and with '\\0': " << std::strlen(testing4.c_str()) << '\n';

    //works fine!
    std::cout << "string created with '\\0' without concat: " << testing5 << '\n';
    std::cout << "string created with '\\0' without concat: " << testing5.size() << '\n';
    std::cout << "string created with '\\0' without concat: " << testing5.c_str() << '\n';
    std::cout << "string created with '\\0' without concat: " << std::strlen(testing5.c_str()) << '\n';

    //works only because we knew how many chars to take!
    std::cout << "string created without '\\0' but size was known (but you cannot use strlen!): " << testing6 << '\n';
    std::cout << "string created without '\\0' but size was known (but you cannot use strlen!): " << testing6.size() << '\n';
    std::cout << "string created without '\\0' but size was known (but you cannot use strlen!): " << testing6.c_str() << '\n';
    std::cout << "string created without '\\0' but size was known (but you cannot use strlen!): " << std::strlen(testing6.c_str()) << '\n';
}

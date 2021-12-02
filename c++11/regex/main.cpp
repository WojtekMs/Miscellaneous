#include <iostream>
#include <regex>
#include <string>
 
int main()
{
   std::string text{"-3 +  /^% -7"};
   std::smatch match;
   std::regex pattern(R"((\+|\-|\/|\*|\%|\^|\$|\!)(?=\D))");
   std::regex_search(text, match, pattern);
   std::cout << match.size() << '\n';
//    for (auto i = 0; i < match.size(); ++i) {
//        std::cout << i << ": " << match[i].str() << '\n';
//    }
   std::sregex_iterator operators_begin = std::sregex_iterator(begin(text), end(text), pattern);
   auto operators_end = std::sregex_iterator();
    for (;operators_begin != operators_end; ++operators_begin) {
        std::cout << operators_begin->str() << '\n';
    }
 
}

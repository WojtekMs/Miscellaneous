# Benchmark

## Raw Loop vs Ranges::Views
Raw loop is a little bit faster than `std::views::reverse`, but the latter is much less error prone and much more elegant. Worth using.

## String Ref vs String View
Taking parameter as `const std::string&` was as fast as taking a parameter as `std::string_view`, however when it comes to the latter it can be dangerous, because the programmer must take care himself about the lifetime of the original string passed as parameter. Passing a temporary object to a function taking `std::string_view` results in undefined behaviour! 

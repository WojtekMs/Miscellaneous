#include <iostream>
#include <source_location>
#include <string>

void log_debug(std::string msg, std::source_location src = std::source_location::current())
{
  std::cerr << "[DEBUG]:" << src.file_name() << ":" << src.line() << ":" << src.column() << ":" << src.function_name() << ":"
            << msg << "\n";
}

int main()
{
  // can be constexpr
  constexpr auto src = std::source_location::current();
  static_assert(src.line() == 14);
  // the column which enters current() function
  static_assert(src.column() == 53);
  static_assert(src.file_name() == "main.cpp");
  static_assert(src.function_name() == "int main()");

  // notice how std::source_location is always constructed when the function is called
  // it contains information about the place it was called at  
  log_debug("Everything went clean");
}

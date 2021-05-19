#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
//reads entire file into stream and then we can have it as a string
  system("ls -l > test.txt");
  std::stringstream fileContents{};
  fileContents << std::ifstream("test.txt").rdbuf();
  std::cout << fileContents.str();
}

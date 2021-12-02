#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

void displayOnScreenWhatIsInsertedOnKeyboard()
{
  std::ofstream file{"output.txt"};
  // clang-format off
    std::copy(std::istream_iterator<std::string, char>(std::cin), //int means the type passed to the input stream, char means the sign that is used by stream (could also be wchar_t), std::cin is the stream used by this iterator
    std::istream_iterator<std::string, char>(), //default istream_iterator means error of input [until eof, data of the wrong type or another error]
    std::ostream_iterator<std::string, char>(file, " ")); //template arguments are the same as in the istream_iterator, std::cout means the stream used by the ostream_iterator, " " means the sign that is used to seperate elements in the stream
    file.close();
    //this could be saved to a container also
  // clang-format on
}

void displayOnScreenWhatIsInsertedFromFile(const std::string& fileName)
{
  std::ifstream file(fileName);
  std::copy(std::istream_iterator<std::string, char>(file),
            std::istream_iterator<std::string, char>(),
            std::ostream_iterator<std::string, char>(std::cout, " "));
  file.close();
}

int main(int argc, char* argv[])
{
  if (argc == 2) {
    displayOnScreenWhatIsInsertedFromFile(argv[1]);
  }
  displayOnScreenWhatIsInsertedOnKeyboard();
}

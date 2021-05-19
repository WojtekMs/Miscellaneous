#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

void example1() {
  std::stringstream stream{};
  std::string msg{"00021"};
  char destroy_buffer[2];
  stream.str(msg);
  for (int i = 0; i < 3; i++) {
    std::cout << "inside stream: " << stream.str() << '\n';
    // stream.str() is not affected by this command
    stream.getline(destroy_buffer, 2);
    // stream.str() is not affected by this command either
    stream.ignore(2);
    // stream.str() is not affected by this command either
    stream >> destroy_buffer;
    std::cout << destroy_buffer << '\n';
  }

}

int main()
{

    std::stringstream stream{};
    stream << "example code" << 5 << 127 << '\n';
    std::cout << stream.str();
    stream.str("abba\n");
    std::cout << stream.str();
    stream << "example code again!" << 123809 << '\n';
    std::cout << stream.str();
    stream.str("");
    stream << "example code again!" << 9 << '\n';
    std::cout << stream.str();
    std::vector<std::string> args{};
    //CAREFUL! this sets eof bit on the stream, hence making it unavailable for further use!
    std::copy(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>{}, std::back_inserter(args));
    stream.str("");
    stream << "HELLO WORLD!\n";
    std::cout << stream.str();
    if (stream.eof()) {
        //you cannot use the stream until you clear the bit!
        std::cout << "end of file is reached!\n";
        stream.clear();
    }
    stream << "HELLO WORLD!\n";
    std::cout << stream.str();
    



}

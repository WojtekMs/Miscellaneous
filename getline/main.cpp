#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream output_file("plik.txt", std::ios::out);
    output_file << "Robert\n";
    output_file.flush();
    output_file.close();
    std::ifstream input_file("plik.txt", std::ios::in);
    std::string line{};
    while (std::getline(input_file, line)) { //does not append delim to the line
                                            //however it removes delim from the stream
                                            //eof bit is set when end of file occurs, bool returns false
        std::cout << line;
    }
    input_file.close();
}

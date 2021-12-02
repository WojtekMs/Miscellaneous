#include <cstring>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void print_manual()
{
  std::cout << "Program ma przyjmować 2 parametry z linii komend.\n"
            << "Pierwszy to katalog, w którym będą pliki txt ze stanami gier na torach,\n"
            << "a drugi opcjonalny to plik wyjściowy, w którym mają zostać zapisane przetworzone wyniki.\n"
            << "Jeśli drugi parametr nie zostanie podany to wyniki mają zostać wypisane na ekran.\n";
}

int main(int argc, char** argv)
{
  if (argc > 1) {
    if (!std::strcmp(argv[1], "-h") || !std::strcmp(argv[1], "--help")) {
      print_manual();
    }
  }
}
  // std::filesystem::directory_iterator(".")
  // std::vector<std::string> file_names;
  // for (auto& dir_entry : std::filesystem::directory_iterator(std::filesystem::current_path())) {
  //   file_names.push_back(dir_entry.path().filename());
  // }
  // std::ifstream first_file(file_names[0]);
  // std::string line;
  // while(std::getline(first_file, line)) {
  //   std::cout << line << '\n';
  // }
  // first_file.close();
  // std::cout << std::filesystem::current_path() << "\n";
}

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
  std::string text{"text\n------\n"}; // std::ios::out also calls std::ios::trunc (erases the content of the file!)
  std::string filename{"recipes.txt"}; //in order to append anything one should use std::ios::app
  std::ofstream file(filename.c_str(), std::ios::in); //in order to be able to edit the contents of the entire file
                                                      //one should use std::ios::in | std::ios::out
  file << text;
  file << text;
  file.close();
  file.open(filename.c_str(), std::ios::in | std::ios::ate);
  file << "appended";
}

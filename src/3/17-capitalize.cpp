#include <vector>
#include <string>
#include <iostream>

int upper_string_in_vector(int argc, char *argv[]){
  std::vector<std::string> strong;
  strong.push_back("wat");
  strong.push_back("wat2");

  for (std::string &c: strong) {
    for (char &ch: c) {
      ch = std::toupper(ch);
    }
    std::cout << c << std::endl;
    }
  return 0;
}

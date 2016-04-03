#include <vector>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {

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

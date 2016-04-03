#include <iostream>
#include <string>

std::string a() {
  std::cout << "a" << std::endl;
  return "1";
}

std::string b() {
  std::cout << "b" << std::endl;
  return "2";
}

std::string c() {
  std::cout << "c" << std::endl;
  return "c";
}

int main(int argc, char *argv[]) {

  // there is no guarantee which one execute first
  std::string result = b() + (a() + c()) + b();
  std::cout << result << std::endl;

  return 0;
}

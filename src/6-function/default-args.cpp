#include <string>
#include <iostream>


std::string screen(int sz, int sz2, char wut = '*') {
  // here char is converted into unsigned int then to_string,
  // space == 32
  std::string result = "jar" + std::to_string(sz2) + std::to_string(wut);

  // this way char is appended to string
  result += wut;
  result.push_back(wut);
  return result;
}

// this adds default param..
std::string screen(int sz = 10, int sz2 = 22, char);

int default_args_main(int argc, char *argv[]) {

  // will print jar2232**
  std::string wat = screen();
  std::cout << wat << std::endl;

  return 0;
}

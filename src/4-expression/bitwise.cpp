#include <iostream>

void bitwise_operator(int argc, char *argv[]) {

  int a = 5;
  int b = a >> 1;
  int c = ~a;

  // shift
  std::cout << b << std::endl;

  // NOT
  std::cout << c << std::endl;

  // AND
  int d = b & c;
  std::cout << "AND" << d << std::endl;

  // OR
  std::cout << (b | c) << std::endl;

  // XOR
  std::cout << (b ^ c) << std::endl;

}

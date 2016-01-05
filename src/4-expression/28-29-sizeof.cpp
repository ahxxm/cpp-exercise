#include <vector>
#include <string>
#include <iostream>

void sizeoff(int argc, char *argv[]) {

  // 28: print built in type's size
  std::cout << "size of string type: " << sizeof(std::string)<< std::endl;
  std::cout << "size of int type: " << sizeof(int)<< std::endl;

  // 29: result
  int x[10];
  int *p = x;
  // 10, whole size of array / single element's
  std::cout << sizeof(x) / sizeof(*x)<< std::endl;
  // 2, size of int pointer / size of int, 8 / 4
  // FIXME: why 8?
  std::cout << sizeof(*p) << std::endl;
  std::cout << sizeof(p) / sizeof(*p)<< std::endl;
}

#include <vector>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {

  // 28: print built in type's size
  std::cout << "size of string type: " << sizeof(std::string)<< std::endl;
  std::cout << "size of int type: " << sizeof(int)<< std::endl;

  // 29: result
  int x[10];
  int *p = x;
  // 10, whole size of array / single element's, 40 4
  std::cout << "size of array, array element" << std::endl;
  std::cout << sizeof(x) << " " << sizeof(*x)<< std::endl;
  // 2, size of int pointer / size of int, 8 / 4
  std::cout << "size of int *, int "<< sizeof(p) << " " << sizeof(*p) << std::endl;


  // 32: explain loop
  // ptr is a pointer to first eleent in array ia, ix is count of element used in
  // the loop. ix starts in 0 and compares with size, so ptr reaches end first.
  const int size = 5;
  int ia[size] = {1, 2, 3, 4, 5};
  for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size; ++ix, ++ptr) {
    std::cout << ix << std::endl;
    std::cout << *ptr << std::endl;
  }
}

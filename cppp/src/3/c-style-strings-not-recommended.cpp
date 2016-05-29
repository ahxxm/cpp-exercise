#include <string>
#include <iostream>
#include <vector>


int main(void) {

  // string functions C-style: must pass null-ended arrays
  // not counting the tail null
  // std::cout << strlen("123") << std::endl;

  // 0 for equality, positive if str1>str2, vice versa
  // std::cout << strcmp("123", "123") << std::endl;

  // c++11 does not allow string literal to be converted
  // to char* ...
  // std::cout << std::strcat("123", "455") << std::endl;


  // strcpy(destination, source); copies string to another one;


  // init vector using array is also not recommended
  int ia[] = {1, 2, 3, 4};
  std::vector<int> iv1(std::begin(ia), std::end(ia));
  std::vector<int> iv2(ia + 1, ia + 2);
  std::cout << iv1.size() << std::endl;
  std::cout << iv2.size() << std::endl;
}

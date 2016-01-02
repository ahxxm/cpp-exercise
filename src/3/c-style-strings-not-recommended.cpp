#include <string>
#include <iostream>

void c_style_string(int argc, char *argv[]){

  // string functions C-style: must pass null-ended arrays
  // not counting the tail null
  std::cout << strlen("123") << std::endl;

  // 0 for equality, positive if str1>str2, vice versa
  std::cout << strcmp("123", "123") << std::endl;

  // c++11 does not allow string literal to be converted
  // to char* ...
  // std::cout << std::strcat("123", "455") << std::endl;


  // strcpy(destination, source); copies string to another one;
}

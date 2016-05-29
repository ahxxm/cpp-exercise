#include <string>
#include <iostream>

// This return value could be lvalue
char &get_val_in_string(std::string &str, std::string::size_type ix) {
  return str[ix];
}


int main(void) {
  std::string s = "Hello";
  get_val_in_string(s, 0) = 'h';
  std::cout << s << std::endl;

  return EXIT_SUCCESS;
}

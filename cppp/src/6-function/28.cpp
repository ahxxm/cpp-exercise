#include <initializer_list>
#include <iostream>
#include <string>


// 28: type of e
// is const std::string
void error_msg(std::initializer_list<std::string> il) {
  for (const std::string &e : il) {
    std::cout << e << std::endl;
  }
}
int main(void) {
  std::initializer_list<std::string> ii {"123", "456"};
  error_msg(ii);
  return 0;
}

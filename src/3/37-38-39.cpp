#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  // 37: this snippet prints y a y line by line
  // const char ca[] = {'y', 'a', 'y'};
  // const char *cp = ca;
  // while (*cp) {
  // std::cout << *cp << std::endl;
  // ++cp;
  // };

  // FIXME: why these will cause the first string definition
  // to cout?

  // 38: why adding 2 pointers meaningless?
  // because pointers are address?

  // 39: compare 2 string
  // FIXME: any special comparison technique?
  std::string a = "wuto";
  std::string b = "wut";

  std::string result = "equal";
  if (a < b) {
    result = "less";
  } else {
    if (a > b) {
      result = "greater";
    }
  }

  std::cout << result << std::endl;
}

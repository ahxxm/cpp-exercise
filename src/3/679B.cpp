#include <string>
#include <iostream>

int loopstring(int argc, char *argv[]){

  // 6: change all char in a string into `x`
  // notice that single quote means char, double
  // means string literal
  // 7: specify char in for loop works fine.
  std::string pend("wat");
  for (char & x: pend) {
    x = 'x';
  }

  // 9
  // though undefined, it actually print a blank line..
  std::string s;
  std::cout << s[1] << std::endl;

  // 11
  // legal, it just did nothing..
  const std::string ss = "Keep out!";
  for (auto & c: ss) {
    /*  ... */
  }

  return 0;
}

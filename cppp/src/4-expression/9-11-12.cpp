#include <iostream>


int main(int argc, char *argv[]) {

  // 9: explain this if
  // if: FIRST, `cp` in if means `cp != false`, where false will be 0.
  // if cp==0, then `if` will check if `*cp!=0`.
  // In this case, cp is not 0, `*cp` won't be evaluated.
  const char *cp = "Hello World";
  if (cp) {
    std::cout << "cp does not equal to false" << std::endl;
  };
  if (cp && *cp) {
    // here cp points to first char of that array
    std::cout << *cp << std::endl;
    std::cout << *(++cp) << std::endl;
  };

  // 11:
  int a = 1;
  int b = 0;
  int c = -1;
  int d = -2;
  if (a > b && b > c && c > d) {
    std::cout << "wat" << std::endl;
  }

  // 12: logical operand sequence
  int i = 0;
  int j = 1;
  int k = 19;

  if (i != j < k) {
    // this will evaluate j<k first!!!
    // it means: if j < k, and i does not equal to their comparison result..
    std::cout << "wut" << std::endl;
  }
}

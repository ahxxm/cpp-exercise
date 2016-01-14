#include <string>
#include <iostream>

int main(int argc, char *argv[]) {

  int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto ia2(ia); // equals to auto ia2(&ia[0]);
  ia2[4] = 4; // this actually changes ia[4]
  std::cout << ia[4] << std::endl;
  std::cout << "" << std::endl;


  // e points to first element in array
  for (int *e = ia; *e != 10; e++) {
    std::cout << *e << std::endl;
  }
  std::cout << "" << std::endl;

  // the same as above
  decltype(ia) ia3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ia3[5] = 10;

  // begin/end are std method..
  int *ia_begin = std::begin(ia), *ia_end = std::end(ia);
  while (ia_begin != ia_end && ia_begin >= 0) {
    std::cout << *(++ia_begin) << std::endl;
    ++ia_begin;
  }

  // type of n is ptrdiff_t
  auto n = std::end(ia3) - std::begin(ia3);
  std::cout << n << std::endl;


  int *p = &ia3[2];
  int p2 = p[1]; // equivalent to *(p+1), ia[3]
  int p3 = p[-2]; // equivalent to *(p-2), ia[0]
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;


  return 0;
}

#include <iostream>
#include "gtest/gtest.h"


// bool (*pf)(const int &a, const int &b);
// can be called directly without dereference..
// pf(1, 2);
// (*pf)(1, 2);

// void ff(int *);
// void ff(unsigned int);
// void (*pf1) (unsigned int) = ff; // points to unsigned int one

// TEST(PointerToOverloadedFunctionTest, PointToSameParamType) {
//
// };


int main(int argc, char *argv[]) {
  std::cout << "Nothing here." << std::endl;

  return 0;
}

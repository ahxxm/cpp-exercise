#include "gtest/gtest.h"
#include <string>


void test() {
  // allocate large enough raw, untyped memory to hold object
  // run appropriate constructor
  // return pointer
  std::string *sp = new std::string("str");
  std::string *arr = new std::string[10];

  delete sp; // destroy pointer and free pointed memory
  delete [] arr; // destroy 10 strings and free memory

};


TEST(MemAllocationTest, SomeTest) {
  test();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

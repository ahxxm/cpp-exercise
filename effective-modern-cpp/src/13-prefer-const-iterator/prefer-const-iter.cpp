#include "gtest/gtest.h"

// use const whenever practical

// const iterator: STL equivalent to const pointer



TEST(ConstIterTest, SomeTest) {

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

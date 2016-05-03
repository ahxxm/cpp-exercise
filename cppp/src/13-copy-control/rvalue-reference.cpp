#include <iostream>
#include <utility>
#include "gtest/gtest.h"


void rvalue_reference() {

  // variables are lvalues..
  int k = 42;
  // int &&r = k; // can't do this

  // after move, we can't make any assumptions
  // about j
  int &&j = 2 * 2;
  int &&jj = std::move(j);
  std::cout << k << std::endl;
  std::cout << jj << std::endl;
}


TEST(RValueReferenceTest, SomeTest) {
  rvalue_reference();
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

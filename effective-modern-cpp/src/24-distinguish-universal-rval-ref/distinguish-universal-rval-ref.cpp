#include "gtest/gtest.h"


// universal ref: include type deduction
template<typename T>
void f(T &&) {};

int v1 = 1;
auto &&v = v1;

// rvalue ref: no type deduction
void f(int &&) {};

int &&vv = 1;



TEST(RefTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

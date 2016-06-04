#include "gtest/gtest.h"


// ref collpase:
// - param is lvalue: T is lvalue reference, T& && collapse to T&
// - param is rvalue: T is non-reference
template<typename T>
void f(T &&param);


TEST(RefCollapseTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

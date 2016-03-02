#include "gtest/gtest.h"

// 33: how many operands may an function call operator take
// seems no limit
struct Foo {
  int operator() (const int i, const int j){
    return 42;
  };
};


TEST(FunctionCallTest, SomeTest) {
  Foo a;
  EXPECT_EQ(a(1, 2), 42);
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

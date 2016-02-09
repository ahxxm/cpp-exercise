#include "gtest/gtest.h"
#include <algorithm>
#include <vector>


TEST(LambdaTest, SomeTest) {
  // [capture list] (params) -> return type {body}
  // either or both params and retrn type can be omitted
  // NO default args
  auto f = []()->int{return 42;};
  auto g = [] {return 44;};
  int j = f();
  int k = g();
  EXPECT_EQ(j, 42);
  EXPECT_EQ(k, 44);

  // capture pass name to lambda function scope
  int i = 2;
  auto cap = [i]()->int {return i * i;};
  EXPECT_EQ(cap(), 4);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

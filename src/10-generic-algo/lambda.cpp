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

  // 14
  auto sum = [](const int& i, const int& j)->int {return i + j;};
  int summer = sum(1, 2);
  EXPECT_EQ(summer, 3);

  // 15: capture pass name to lambda function scope
  int i = 2;
  auto cap = [i]()->int {return i * i;};
  EXPECT_EQ(cap(), 4);

  // by default lambda captures value:
  // copy into function when created
  auto v_lambda = [i] {return i;}; // value by default
  auto v_lambda2 = [&, i] {return i;}; // explicit value by default
  auto r_lambda = [=, &i] {return i;}; // value by default, &i means reference
  i = 3;

  EXPECT_EQ(v_lambda(), 2);
  EXPECT_EQ(v_lambda2(), 2);
  EXPECT_EQ(r_lambda(), 3);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

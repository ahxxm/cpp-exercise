#include <algorithm>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"


// 20
int count_if_lambda() {
  std::vector<int> ve = {1, 2, 3, 4, 1, 2, 3};
  int count_one = std::count_if(ve.begin(), ve.end(), [](int i)->int {return i == 1;});
  std::cout << count_one << std::endl;
  return count_one;
}

// 21
int decrease_lambda() {
  int i = 10;
  auto f = [&i]() {
    while (i != 0) {
      --i;
    }
  };
  f();
  return i;
}


TEST(LambdaeTest, MoreTest) {
  EXPECT_EQ(count_if_lambda(), 2);
  EXPECT_EQ(decrease_lambda(), 0);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

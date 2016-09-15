#include "gtest/gtest.h"

// By considering the terms in the Fibonacci sequence whose values do not exceed four million,  find the sum of the even - valued terms.

#define N 4000000

int solve() {
  int i = 1, j = 2;
  int sum = j;
  int tmp;

  // odd, even odd odd, even odd odd, ...
  int flag = 0;
  while(j < N) {
    tmp = i + j;
    i = j;
    j = tmp;
    flag += 1;
    if(flag == 3) {
      sum += tmp;
      flag = 0;
    }
  }
  return sum;
}

TEST(MoreClassExerciseTest, SomeTest) {
  EXPECT_EQ(solve(), 4613732);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

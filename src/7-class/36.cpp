#include "gtest/gtest.h"

struct X {
  // problem: requires base to be initialized
  // X (int i, int j): base(i), rem(base % j) {};

  // fix: make rem a getter

  // fix 2: use i and j directly
  // % is mod
  X (int i, int j): base(i) {
    rem = i % j;
  };
public:
  int rem, base;
};

TEST(MoreClassExerciseTest, SomeTest) {
  X x = X(1, 2);
  EXPECT_EQ(x.base, 1);
  EXPECT_EQ(x.rem, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

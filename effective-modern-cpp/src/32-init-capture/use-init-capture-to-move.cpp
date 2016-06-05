#include "gtest/gtest.h"

// C++11 does not give a way to **move**
// object into clojure
// C++14 does

TEST(InitCaptureTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

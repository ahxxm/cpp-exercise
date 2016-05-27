#include "gtest/gtest.h"

// auto advantage:
// - avoid uninitialized
// - avoid verbose declaration
// - hold clojure
// - refactor friendly


// std::function holds instantiation of a clojure
// auto lambda has the same type as clojure


TEST(AutoTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

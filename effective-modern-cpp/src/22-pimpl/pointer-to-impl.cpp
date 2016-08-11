#include "gtest/gtest.h"


// pointer to implementation
// reduce compile dependencies between implementation and clients
// reduce recompile time, data hide, binary compatibility


TEST(PImplTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

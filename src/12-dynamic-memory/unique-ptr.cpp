#include "gtest/gtest.h"
#include <memory>


TEST(UniquePtrTest, SomeTest) {
  // unique_ptr "owns" the pointer
  // release() makes unique_ptr nullptr, and returns the pointer
  int j = 42;
  int *u = &j;
  std::unique_ptr<int> u1(u);
  auto rel = u1.release();
  EXPECT_EQ(*rel, j);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

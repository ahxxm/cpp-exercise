#include "gtest/gtest.h"
#include <memory>


TEST(UniquePtrTest, SomeTest) {
  // unique_ptr "owns" the pointer: does not support copy/assign
  // release() makes unique_ptr nullptr, and returns the pointer
  int j = 42;
  int k = 42;
  int *u = &j;
  int *kk = &k;
  std::unique_ptr<int> u1(u);
  auto rel = u1.release();
  EXPECT_EQ(*rel, j);

  // reset() delete the object to which u1 points..
  // reset with pointer makes it point to that object
  u1.reset(kk);
  auto jar = u1.release();
  EXPECT_EQ(*jar, k);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

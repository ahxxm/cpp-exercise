#include "gtest/gtest.h"
#include <iostream>
#include <string>

template <typename T>
bool aIsLongerThanb(T &&a, T &&b) {
  if (a > b) {
    return true;
  } else {
    return false;
  }
}


TEST (CompareStringTest, Something) {
  const std::string a = "wutt";
  const std::string b = "wut";
  const std::string c = "wu";
  EXPECT_EQ(aIsLongerThanb(b, a), false);
  EXPECT_EQ(aIsLongerThanb(a, c), true);
}

int main(int argc, char *argv[]) {

  // 38: why adding 2 pointers meaningless?
  // because pointers are address?

  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

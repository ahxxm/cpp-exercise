#include "gtest/gtest.h"
#include <iostream>
#include <string>


bool aIsLongerThanb(const std::string &a, const std::string &b) {
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

  // 37: this snippet prints y a y line by line
  // const char ca[] = {'y', 'a', 'y'};
  // const char *cp = ca;
  // while (*cp) {
  // std::cout << *cp << std::endl;
  // ++cp;
  // };

  // FIXME: why these will cause the first string definition
  // to cout?

  // 38: why adding 2 pointers meaningless?
  // because pointers are address?

  // 39: compare 2 string
  // FIXME: any special comparison technique?
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"

// scoped
enum color {yellow, red, green};

// unscoped
enum {integer = 1, floating = 2};


TEST(EnumTest, SomeTest) {

  // enumerator values start at 0,
  // increment by 1 by default.
  color test_color = yellow;
  color wut = color::green;

  EXPECT_EQ(test_color, 0);
  EXPECT_EQ(wut, 2);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

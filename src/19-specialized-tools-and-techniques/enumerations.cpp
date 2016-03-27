#include "gtest/gtest.h"

// unscoped, enum struct
// specify size
enum color: unsigned long long {yellow, red, green};

// unnamed, unscoped
enum {integer = 1, floating = 2};

// scoped
enum class height {low, mid, high};


TEST(EnumTest, SomeTest) {

  // enumerator values start at 0,
  // increment by 1 by default.
  color test_color = yellow;
  color wut = color::green;

  // scoped enum are not implicitly converted
  // int higher = height::low;
  auto higher = height::high;

  EXPECT_EQ(test_color, 0);
  EXPECT_EQ(wut, 2);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

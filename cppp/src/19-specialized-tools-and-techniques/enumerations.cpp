#include "gtest/gtest.h"

// unscoped, enum struct
// specify size:
// - scoped ones are int
// - unscoped ones are not determined, but will be large enough.
enum color: uint64_t {yellow, red, green};

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

  // union values seems unsigned
  unsigned int j = 0;
  unsigned int floating = 2;
  EXPECT_EQ(test_color, j);
  EXPECT_EQ(wut, floating);
  EXPECT_EQ((unsigned int)higher, floating);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

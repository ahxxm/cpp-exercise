#include <iostream>
#include "gtest/gtest.h"


class SmallInt {
public:
  explicit SmallInt(const int i = 0): val(i) {
    if (i < 0 || i > 255) {
      std::cout << "Bad Small int value." << std::endl;
      val = 0;
    }
  };

  operator int() const {return val;}

  // this conversion won't happen automatically
  explicit operator double() const {return 1.0;};
private:
  std::size_t val;
};


TEST(ConversionOperatorTest, SomeTest) {
  SmallInt a(256);
  EXPECT_EQ(static_cast<int>(a), 0);


  SmallInt b(255);
  EXPECT_EQ(static_cast<int>(b), 255);

  // DISABLE this because `explicit` makes it a constructor,
  // style guide suggests explicit for single param constructor.
  // which avoids ambiguity.

  // implicit convert
  // does not reconstruct object
  // b = 3;
  // EXPECT_EQ(static_cast<int>(b), 3);
  // EXPECT_EQ(static_cast<int>(b + 1000), 1003);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

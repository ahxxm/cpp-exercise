#include "gtest/gtest.h"

// abstract base class can't be a type..
struct Pure {
  virtual int print() = 0;
};

struct Derived: Pure {
  int print() {return 42;};
};

TEST(PureVirtualTest, SomeTest) {
  Derived b;
  EXPECT_EQ(b.print(), 42);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include <string>
#include "gtest/gtest.h"


// must be a member function
struct Foo {
  std::string operator[](std::size_t) {
    std::string b = "42";
    return b;
  }
};


TEST(SubscriptTest, SomeTest) {
  Foo a;
  EXPECT_EQ(a[1], "42");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

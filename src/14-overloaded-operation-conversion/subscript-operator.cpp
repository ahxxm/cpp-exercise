#include "gtest/gtest.h"
#include <string>

// must be a member function
class Foo {
public:
  std::string &operator[](std::size_t n) {
    *a = "42";
    return *a;
  }

private:
  std::string *a;
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

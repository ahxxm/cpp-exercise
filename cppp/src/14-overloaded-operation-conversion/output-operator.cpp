#include <iostream>
#include <string>
#include "gtest/gtest.h"


class Foo {
public:

  void operator>>(std::string &i) {
    i = "naive";
  };

  std::ostream &operator<<(std::ostream &os) {
    os << "simple" << std::endl;
    return os;
  };
};


TEST(OutputTest, SomeTest) {
  std::string j;
  Foo a;
  a >> j;
  EXPECT_EQ(j, "naive");

  a << std::cout;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

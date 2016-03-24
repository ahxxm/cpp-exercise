#include "gtest/gtest.h"

namespace ns {
  class Foo {
  public:
    int i = 42;
  };
}



TEST(NamespaceTest, SomeTest) {
  auto a = ns::Foo();
  EXPECT_EQ(a.i, 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"


class Bar {
public:
  int i = 0;
};


// namespace can be defined in several parts
// either define a new namespace or adds to an existing one
namespace ns {
  class Foo {
  public:
    int i = 42;
  };
}

// association
namespace n = ns;


TEST(NamespaceTest, SomeTest) {
  auto a = ns::Foo();
  EXPECT_EQ(a.i, 42);

  auto j = ns::Foo();
  EXPECT_EQ(j.i, 42);

  // explicit global namespace
  auto b = ::Bar();
  EXPECT_EQ(b.i, 0);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

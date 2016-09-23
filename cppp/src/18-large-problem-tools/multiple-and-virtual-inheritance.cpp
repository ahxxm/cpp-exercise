#include "gtest/gtest.h"

class Foo {
public:
  int i = 1;
  Foo() = default;
  explicit Foo(int);
};

class Bar {
public:
  int j = 2;
  Bar() = default;
  explicit Bar(int);
};


// multiple inheritance
class A: public Foo, public Bar {
public:
  // required by custom constructor
  A() = default;

  // must define its own Class(int)
  explicit A(int i) {k = i;};
private:
  int k;
};


TEST(InheritanceTest, SomeTest) {
  A a(1);
  EXPECT_EQ(a.i, 1);
  EXPECT_EQ(a.j, 2);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

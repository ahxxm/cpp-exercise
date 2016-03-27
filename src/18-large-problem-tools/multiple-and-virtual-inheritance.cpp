#include "gtest/gtest.h"

class Foo {
public:
  int i = 1;

};

class Bar {
public:
  int j = 2;

};

// multiple inheritance
class A: public Foo, public Bar {

};


TEST(InheritanceTest, SomeTest) {
  A a;
  EXPECT_EQ(a.i, 1);
  EXPECT_EQ(a.j, 2);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

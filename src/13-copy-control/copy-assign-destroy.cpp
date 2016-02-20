#include "gtest/gtest.h"

class Foo {
public:
  // default constructor
  Foo();

  // copy constructor:
  // - first param is reference to class type, or param itself's initialization will
  // drop into infinite loop..
  // - other(if any) params have default values
  // unlike default one, even we defined other constructors, there still
  // will be copy constructor synthesized by compiler.
  Foo(const Foo &);


  int answer = 42;
};


TEST(ConstructorTest, SomeTest) {
  // direct and copy initialization
  Foo direct_foo = Foo();
  Foo copy_foo = Foo(direct_foo);
  EXPECT_EQ(copy_foo.answer, 42);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

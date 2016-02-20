#include "gtest/gtest.h"
#include <string>
#include <iostream>

class Foo {
public:
  // default constructor
  Foo() = default;

  // copy constructor:
  // - first param is reference to class type, or param itself's initialization will
  // drop into infinite loop..
  // - other(if any) params have default values
  // unlike default one, even we defined other constructors, there still
  // will be copy constructor synthesized by compiler.
  Foo(const Foo &) {

  };

  // overloaded assignment operator
  Foo &operator= (const Foo &) {
    return *this;
  };

  Foo &operator+= (const int &j) {
    std::cout << "Answer is 42, nothing changed." << std::endl;
    return *this;
  };


  int answer = 42;


  // destructor takes no params, can't be overloaded
  ~Foo() {};
};


// 5: write copy constructor for this class
class HasPtr {
public:
  HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {};

  std::string get_ps() {
    return *ps;
  }

  HasPtr(HasPtr &hs) {
    ps = new std::string(hs.get_ps());
  }

private:
  std::string *ps;
  int i;
};


TEST(ConstructorTest, SomeTest) {
  // direct and copy initialization
  Foo direct_foo = Foo();
  Foo copy_foo = Foo(direct_foo);
  EXPECT_EQ(copy_foo.answer, 42);

  copy_foo += 1;
  EXPECT_EQ(copy_foo.answer, 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

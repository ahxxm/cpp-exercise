#include <iostream>
#include <string>
#include "gtest/gtest.h"


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

  Foo &operator+= (const int &) {
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
  explicit HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {};

  std::string get_ps() {
    return *ps;
  }

  // 22: copy constructor and copy assignment operator
  HasPtr(HasPtr &hs) {
    ps = new std::string(hs.get_ps());
  }

  // constructor allocates dynamic memory
  // so it needs a destructor to free these memory
  ~HasPtr() {
    delete ps;
  }

  // assignment operator, in case
  // ps is freed when calling function of HasPtr
  HasPtr &operator=(HasPtr &hs) {
    std::string ps = hs.get_ps();
    this->ps = &ps;
    i = hs.i;
    return *this;
  }

  // define as deleted functions
  // no -= then.
  HasPtr &operator-=(const int &j) = delete;

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

  HasPtr j("jar");
  std::string jar = j.get_ps();
  HasPtr jj(j);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

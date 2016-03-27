#include "gtest/gtest.h"
#include <iostream>



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

  namespace nested {
    int i = 1;
  }
}

// association
namespace n = ns;
namespace ni = ns::nested;


void f() {
  // using derivative:
  // lifting the namespace members into the
  // nearest scope that contains both
  // the namespace itself and the using directive.
  using namespace ns::nested;
  // FIXME: "injects 1 into global namespace"
  // the book says...
  ++i;
  std::cout << i << std::endl;

}


namespace A {
  class C {
    friend void f2() {};
    friend void f(const C&) {};
  };
}


TEST(NamespaceTest, SomeTest) {
  auto a = ns::Foo();
  EXPECT_EQ(a.i, 42);

  auto j = ns::Foo();
  EXPECT_EQ(j.i, 42);

  auto k = ni::i;
  EXPECT_EQ(k, 1);

  // explicit global namespace
  auto b = ::Bar();
  EXPECT_EQ(b.i, 0);


  f();
  EXPECT_EQ(ns::nested::i, 2);


  // A::f through friend declaration
  A::C cobj;
  f(cobj);
  // f2(); // not declared

  // using brought C into current scope
  // when same name exists, C will be added
  // to overload set
  using A::C;
  C cobj2;
  f(cobj2);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

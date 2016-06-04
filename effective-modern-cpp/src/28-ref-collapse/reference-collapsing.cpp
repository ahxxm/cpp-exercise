#include <iostream>
#include "gtest/gtest.h"


// ref collpase:
// - param is lvalue: T is lvalue reference, T& && collapse to T&
// - param is rvalue: T is non-reference
template<typename T>
void f(T &&param);


// ref collapse happen in 4 contexts
// 1. template instantialtion
// 2. type generator for auto(same as 1, see Item-2)
template <typename T>
void func(T &&) {}

class Widget {};
Widget widgetFactory() {
  return Widget();
}

void template_ins() {
  Widget w;
  func(w); // T: Widget&
  func(widgetFactory()); // T: Widget
}

void auto_type() {
  Widget w;

  // w is lvalue ref, w1 is also
  auto &&w1 = w;
  std::cout << &w1 << std::endl;


  // w2 is rvalue ref
  auto &&w2 = widgetFactory();
  std::cout << &w2 << std::endl;

}


// 3. typedef/using
template<typename T>
class Def {
public:
  typedef T&& RR;
};

void typedef_collapse() {
  Def<int&> w; // RR is int& &&, int&
  std::cout << &w << std::endl;
}

// 4. decltype


TEST(RefCollapseTest, SomeTest) {
  template_ins();
  auto_type();
  typedef_collapse();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

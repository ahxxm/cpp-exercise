#include <iostream>
#include "gtest/gtest.h"

// Get deduced info during: edit, compile, runtime

// editor/IDE gets informtaion from compile
// works for simple types.
// "by use it in a way that leads to compiler problems"...
template<typename T>
class TypeDisplayer {};

void view() {
  int a = 10;

  // undefined template 'TypeDisplayer<int>'
  // TypeDisplayer<decltype(a)> aType;
  std::cout << &a << std::endl;

};

// print in function template
template<typename T>
void f(const T &param) {
  // NOT RELIABLE: type be treated as if it had been passed to as a by-value param.
  std::cout << typeid(T).name() << std::endl;
  std::cout << typeid(param).name() << std::endl;
};


void print() {
  int a = 10;
  auto b = &a;

  // std::type_info::name() -> const char*
  // i: int
  // Pi: pointer to int
  // PKi: pointer to k(c)onst int
  std::cout << typeid(a).name() << std::endl;
  std::cout << typeid(b).name() << std::endl;

  // print T and param
  // P13TypeDisplayerIiE
  // P: pointer
  // 13: length of "TypeDisplayer"
  // FIXME: I? E?
  TypeDisplayer<int> i;
  f(&i);

};


TEST(ViewDeduced, SomeTest) {
  view();
  print();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

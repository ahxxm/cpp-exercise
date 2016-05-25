#include <initializer_list>
#include <iostream>
#include "gtest/gtest.h"

// with 1 exception, auto deduction is template deduction.
// "auto plays the role of **T** in the template"


int auto1() {
  auto x = 27;
  // const auto cx = x; // const int
  auto &rx = x; // int &
  rx = 233;
  return x;
}

void auto2() {
  // FIXME: test these
  auto x = 2;
  const auto cx = x;

  auto &&uref1 = x; // int&
  auto &&uref2 = cx; // const int&
  auto &&uref3 = 23; // int&&
  std::cout << &uref1 << std::endl;
  std::cout << &uref2 << std::endl;
  std::cout << &uref3 << std::endl;
}

// array and function decay
void auto3() {
  const char name[] = "ahxxm";
  auto arr1 = name; // char char*
  auto &arr2 = name; // char(&)[]
  std::cout << arr1 << std::endl;
  std::cout << &arr2 << std::endl;
  // delete[] arr1;
  // delete[] &arr2;

  // the same for function
}

void auto4() {
  auto x1 = 27; // int
  auto x2(27); // int
  std::cout << x1 << std::endl;
  std::cout << x2 << std::endl;

  auto x3 = {3}; // std::initializer_list<int> .....
  auto x4 {3}; // "ditto"
  std::cout << &x3 << std::endl;
  std::cout << &x4 << std::endl;
}

// the only different between auto and template deduction:
// - auto assumes braced list means initializer list
// f({1, 2, 3})
template<typename T>
void f(T) {}; // not work

template<typename T>
void f(std::initializer_list<T>) {}; // T is int



TEST(MoreClassExerciseTest, SomeTest) {
  EXPECT_EQ(auto1(), 233);
  auto2();
  auto3();
  auto4();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

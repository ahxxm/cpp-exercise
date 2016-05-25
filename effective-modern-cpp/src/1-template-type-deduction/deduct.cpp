#include <array>
#include <iostream>
#include "gtest/gtest.h"


// Case 1: pointer/reference ParamType
// reasonable deduction
template<typename T>
void f1(T& param) {
  std::cout << &param << std::endl;
};

template<typename T>
void f11(const T &param) {
  std::cout << &param << std::endl;
};

template<typename T>
void f12(T *param) {
  std::cout << &param << std::endl;
};

void case1() {
  int x = 27;
  const int cx = x; // const int
  const int &rx = x; // const ref to x
  const int *px = &x; // const pointer to non-const x

  //          T       param
  f1(x);   // int   , int&
  f1(cx);  // const int, const int&
  f1(rx);  // const int, const int&

  f11(x);  // int, const int&
  f11(cx);  // int, const int&
  f11(rx);  // int, const int&

  f12(&x);  // int *, int *
  f12(px);  // const int, const int *
};


// Case 2: universal ref &&
// - lvalue: T and paramType are &, collapse(?) // FIXME:
// - rvalue: normal rules
template<typename T>
void f2(T &&param) {
  std::cout << &param << std::endl;
};


void case2() {
  int x = 27;
  const int cx = x; // const int
  const int &rx = x; // const ref to x

  //           T      paramType
  f2(x);  // int &,     int &
  f2(cx);  // const int&, const int&
  f2(rx);  // const int&, const int&
  f2(27);  //  int, int &&
};

// Case 3: neither pointer nor ref
// pass by value, copy construct..
template<typename T>
void f3(T param) {
  std::cout << &param << std::endl;
}

void case3() {
  int x = 27;
  const int cx = x; // const int
  const int &rx = x; // const ref to x

  //           T     paramType
  f3(x);  //  int, int
  f3(cx);  // int, int
  f3(rx);  // int, int
};

void const_ptr_to_const() {
  const char* const ptr = "kk";

  // here ptr copied into param, a pointer that points to const char,
  // but can be changed to point to other object
  f3(ptr);
}


// Decay
// array decay into pointer
// function also decay into function pointer
void some_func(int, double) {};
void decay() {
  const char name[] = "J.P.";
  // const char *ptr = name;

  // name is char[], ptr is char*.
  // T is char* ... !
  f3(name);

  // void (*)(int, double);
  f3(some_func);

  // T& prevents decay.

  // T is char[size] ... ! FIXME: verify this
  // this enables to get array size.
  f1(name);

  // T: void (&)(int, double)
  // f1(some_func); // copy needs instantiation
};


template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {
  return N;
};


TEST(TemplateDeductionTest, SomeTest) {
  case1();
  case2();
  case3();
  const_ptr_to_const();
  decay();

  // modern cpp array
  int keyVals[] = {1, 2, 3, 4, 5, 6};
  std::array<int, arraySize(keyVals)> vals;
  EXPECT_EQ(static_cast<int>(vals.size()), 6);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

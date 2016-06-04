#include <vector>
#include <utility>
#include "gtest/gtest.h"

// forward: one function pass its param to another
// goal/perfect: second function receive the same object

// Failures



// Brace initializer
void f(const std::vector<int> &) {}
void f(int) {}


template<typename... Ts>
void fwd(Ts&&... params){
  f(std::forward<Ts>(params)...);
}

void brace_fail() {
  // direct: converts to std::vector implicitly
  f({1, 2, 3});

  // fwd({1, 2, 3});
  // forward fail: {} is not declared as initializer_list
  // , compiler is forbidden to deduced it.

  // fix:
  auto il = {1, 2, 3};
  fwd(il);
}

// 0/NULL as nullptr

// static const member

class Widget {
public:
  // declaration, not definition.
  static const int MinVals = 28;
};

// fix: define
const int Widget::MinVals;

void static_const_fail() {
  f(Widget::MinVals);

  // link fail: undefined ref to static const member.

  // reference are treated like pointers by compiler, pass MinVals
  // ref is the same as pass by pointer, so there has to be memory
  // to be pointed to, thus require it to be defined.
  // note: not all compiler require it to be defined.

  // fwd(Widget::MinVals);

  // fix:
  fwd(Widget::MinVals);
}


// overloaded function/template names
int processVal(int) {
  return 42;
}

int processVal(int, int) {
  return 42;
}

// f takes a function:
// void f(int (*)(int)) {}
// simpler syntax:
void f(int (int)) {}


void overload_name_fail() {
  // fine, compiler knows which processVal is needed:
  // the one that takes 1 int
  f(processVal);

  // fail to know
  // fwd(processVal);
}


TEST(PerfectForwardFailureTest, SomeTest) {
  brace_fail();
  static_const_fail();
  overload_name_fail();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

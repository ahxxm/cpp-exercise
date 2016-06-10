#include <functional>
#include <memory>
#include <utility>
#include "gtest/gtest.h"

// C++11 does not give a way to **move**
// object into clojure
// C++14 does

class Widget {};

void init_capture() {
  auto pw = std::make_shared<Widget>();

  // only in C++14
  // pw: scope in clojure class
  // std::move(pw): scope as the same of lambda expression
  auto func = [pw = std::move(pw)]() {return 42;};

  // emulation in C++11:
  // move construct an object into bind,
  // pass that object to lambda by reference
  // int i = 42;
  // auto func = std::bind([](int &) mutable {}, std::move(i));
  func();

}


TEST(InitCaptureTest, SomeTest) {
  init_capture();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

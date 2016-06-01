#include <iostream>
#include <memory>
#include "gtest/gtest.h"


// all shared_ptr points to object collaborate to
// ensure proper destruction.(by ref count)

// ref count result in double size as raw pointer:
// another pointer to ref count

// +- ref count must be atomic...
// move construction does not affect ref count, faster.


// shared_ptr to same object can have different deleter
class Widget {};


void dif_deleter() {
  auto customDel1 = [](Widget *pw) {delete pw;};
  auto customDel2 = [](Widget *pw) {delete pw;};

  using shared_wid = std::shared_ptr<Widget>;
  shared_wid pw1(new Widget, customDel1);
  shared_wid pw2(new Widget, customDel2);
  std::vector<shared_wid> vpw {pw1, pw2};
  std::cout << &vpw << std::endl;
};


void avoid_raw() {
  // ERROR: undefined control block behavior by
  // creating more than 1 shared_ptr
  auto pw = new Widget;
  // create control block 1
  std::shared_ptr<Widget> spw1(pw);

  // create control block 2
  // std::shared_ptr<Widget> spw2(pw);

  std::cout << &spw1 << std::endl;
  // std::cout << &spw2 << std::endl;
};


TEST(SharedPtrTest, SomeTest) {
  dif_deleter();
  avoid_raw();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

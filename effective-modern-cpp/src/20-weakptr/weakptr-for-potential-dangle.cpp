#include <memory>
#include "gtest/gtest.h"


class Widget {};

// FIXME: weakptr for cache

// FIXME: weakptr for observer pattern:
// subject has no interest control observer's lifetime,
// hold a container of weakptrs, make sure not dangling
// before use.

int check() {
  // weak_ptr is usually? created using shared_ptr
  // check dangling

  auto spw = std::make_shared<Widget>(); // ref_count =1
  std::weak_ptr<Widget> wpw(spw); // still 1!
  spw = nullptr; // rc==0, wpw dangles
  if (wpw.expired()) {
    return 42;
  }
  return 0;
};

void lo() {
  // atomic between check and operation
  auto spw = std::make_shared<Widget>();
  std::weak_ptr<Widget> wpw(spw);

  // lock creates a shared_ptr
  auto spw1 = wpw.lock();
  std::cout << &spw1 << std::endl;
}


TEST(WeakptrTest, SomeTest) {
  EXPECT_EQ(check(), 42);
  lo();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

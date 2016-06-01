#include <memory>
#include "gtest/gtest.h"


class Widget {};

int w() {
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


TEST(WeakptrTest, SomeTest) {
  EXPECT_EQ(w(), 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

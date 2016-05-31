#include "gtest/gtest.h"


// C++98 generates 4: default constructor, destructor,
// copy ctor, copy assignment operator.
// C++11 generates 2 more: move ctor, move assignment operator.

// generate only when it's needed/used, generated functions are
// implicitly public and inline.

// Move: more like more request
// type that aren't move-enabled will be "moved" via copy.
// 2 move NOT independed, will prevent compiler generate the other.

// Copy: 2 synthesized member are independent, declare one
// won't prevent generating the other when needed.


class Widget {
public:
  // move ctor and move assign operator
  // Widget(Widget &&) {};
  // Widget& operator=(Widget &&);
};


TEST(MemberFuncGenTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

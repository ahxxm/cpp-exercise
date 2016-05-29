#include "gtest/gtest.h"


class Widget {
public:
  // & work when Widget is lvalue, && when rvalue
  int doWork() & {return 1;};
  int doWork() && {return 0;};
};


TEST(OverrideTest, SomeTest) {
  Widget w;
  EXPECT_EQ(w.doWork(), 1);
  EXPECT_EQ(Widget().doWork(), 0);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

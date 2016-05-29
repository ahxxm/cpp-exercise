#include "gtest/gtest.h"


class Widget {
public:
  // & work when Widget is lvalue, && when rvalue
  virtual int doWork() & {return 1;};
  virtual int doWork() && {return 0;};
};


class Derived: public Widget {
public:
  // won't compile without specifier
  // int doWork() override {return 2;};

  // explicit and implicit override
  int doWork() & override {return 2;};
  int doWork() && {return 3;};
};


TEST(OverrideTest, SomeTest) {
  Widget w;
  EXPECT_EQ(w.doWork(), 1);
  EXPECT_EQ(Widget().doWork(), 0);

  Derived ww;
  EXPECT_EQ(ww.doWork(), 2);
  EXPECT_EQ(Derived().doWork(), 3);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

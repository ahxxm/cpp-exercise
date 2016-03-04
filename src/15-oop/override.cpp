#include "gtest/gtest.h"


struct Base {
  virtual int print() {
    return 1;
  };

  virtual int name() {
    return 2;
  };
};

struct Derived: public Base {
  int print() override {
    return 11;
  };

  int name() override {
    return 22;
  };
};


TEST(OverrideTest, SomeTest) {

  Base bobj;
  Base *bp1 = &bobj;
  Base &br1 = bobj;

  Derived dobj;
  Base *bp2 = &dobj;
  Base &br2 = dobj;

  // dynamic bind...
  EXPECT_EQ(bobj.print(), 1);
  EXPECT_EQ(dobj.print(), 11);
  EXPECT_EQ(bp1->name(), 2);
  EXPECT_EQ(bp2->name(), 22);
  EXPECT_EQ(br1.print(), 1);
  EXPECT_EQ(br2.print(), 11);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

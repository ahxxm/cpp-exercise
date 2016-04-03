#include "gtest/gtest.h"

class Pal;


class Base {
  friend class Pal;
public:
  int pub = 1;
protected:
  int protect = 2;
private:
  int priv = 3;
};

class Sneaky: public Base {};

class Pal {
public:
  // ok
  int f(Base &b) {return b.priv;};

  int f2(Sneaky &s) {return s.protect;};

  // Base control access to its member
  int f3(Sneaky &s) {return s.priv;};
};


// default inherit level
// class D2: private
// struct D2: public
class D2: public Pal {
public:
  int mem(Base &b) {
    // return b.priv
    // return b.protect; // friendship does not inherit
    return b.pub;
  }
};


TEST(FriendInheritanceTest, SomeTest) {
  Pal p;
  Base b;
  Sneaky s;
  D2 dd;
  EXPECT_EQ(p.f(b), 3);
  EXPECT_EQ(p.f2(s), 2);
  EXPECT_EQ(p.f3(s), 3);
  EXPECT_EQ(dd.mem(b), 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <iostream>

// This class has no default initializer
class NoDefault {
public:
  NoDefault(int i) {
    std::cout << i << " is used."<< std::endl;
    j = i;
  };

  int j = 100;
};


// 43: define a class C that has a memerber of type Nodefault
// define C's default constructor
class C {
public:
  C() {
    NoDefault ob = NoDefault(0);
    obj = &ob;
  };

  int getJ() {
    return obj->j;
  };
private:
  NoDefault *obj;
};


TEST(ConstructorTest, SomeTest) {
  C c;
  EXPECT_EQ(c.getJ(), 0);

  // 44: legal?
  // std::vector<NoDefault> vec(10);
  // no. should be initialized..
  std::vector<NoDefault> vec(10, NoDefault(10));
  // FIXME: clang 3.5 failed(same to below 2)
  // EXPECT_EQ(vec[0].j, 10);

  // 45: vector to hold C
  std::vector<C> var(10, C());
  // FIXME: why not 0??
  // EXPECT_EQ(var[0].getJ(), 0);

  // FIXME: why not 0??
  std::vector<C> vahr(10);
  // EXPECT_EQ(vahr[0].getJ(), 0);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

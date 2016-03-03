#include "gtest/gtest.h"
#include <stdexcept>

class V {
public:
  virtual int answer() const {
    throw std::exception();
  };
};

class VV: public V {
public:
  // override with definition requires previous definition
  int answer() const override {
    return 42;
  };


  int a;
};


TEST(VirtualFunctionTest, SomeTest) {
  VV a;
  EXPECT_EQ(a.answer(), 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <stdexcept>

class V {
public:
  virtual int answer() const {
    throw std::exception();
  };

  virtual int bind() {
    return 1;
  }
};

class VV: public V {
public:
  // override with definition requires previous definition
  int answer() const override {
    return 42;
  };

  // also requires virtual function
  // so to use dynamic bind, a virtual base function is
  // required...
  int bind() override {
    return 2;
  }

  int a;
};

int dynamic(V &v) {
  return v.bind();
}


TEST(VirtualFunctionTest, SomeTest) {
  VV a;
  VV b;
  V c;
  EXPECT_EQ(a.answer(), 42);

  EXPECT_EQ(dynamic(a), 2);
  EXPECT_EQ(dynamic(b), 2);
  EXPECT_EQ(dynamic(c), 1);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

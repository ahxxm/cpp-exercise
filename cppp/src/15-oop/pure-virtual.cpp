#include "gtest/gtest.h"

// abstract base class can't be a type..
struct Pure {
  virtual int print() = 0;
};

struct Derived: Pure {
  int print() {return 42;};
};

// private inherits and make it private..
class PrivateDerive: private Pure {
public:
  int java() {
    return print();
  };
private:
  // int print() override final {
  // no need to override because final
  int print() final {
    return 44;
  };
};

TEST(PureVirtualTest, SomeTest) {
  Derived b;
  EXPECT_EQ(b.print(), 42);

  PrivateDerive pd;
  EXPECT_EQ(pd.java(), 44);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

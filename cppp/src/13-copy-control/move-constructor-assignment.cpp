#include <utility>
#include "gtest/gtest.h"


class Foo {
public:
  Foo() = default;
  explicit Foo(const int &j): i(new int(j)) {}

  // move operator "steals" origin value
  // should assure deleting moved object be harmless

  // also crutial that not free left-hand resources before using right-hand one,
  // because self move assignment
  Foo(Foo &&f) noexcept: i(f.i) {
    f.i = nullptr;
  }

  // move assignment operator
  Foo &operator=(Foo &&f) noexcept {
    // assure self move assignment works
    if (this != &f) {
      // store this value and make a new pointer
      // to i for new Foo.
      int tmp = *f.i;
      i = new int(tmp);
      f.i = nullptr;
    };
    return *this;
  }

  ~Foo() {
    delete i;
  }

  int square() {
    return *i * *i;
  }

private:
  int *i;
};


TEST(MoveTest, SomeTest) {
  Foo a = Foo(3);
  auto b = std::move(a);
  EXPECT_EQ(b.square(), 9);

  Foo c;
  c = std::move(b);
  EXPECT_EQ(c.square(), 9);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

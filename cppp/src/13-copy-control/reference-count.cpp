#include "gtest/gtest.h"
#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t(1)){};

  // copy constructor, ps/use copied from previous one,
  // and increment use.
  HasPtr(const HasPtr &p): ps(p.ps), i(p.i), use(p.use) {++*use;};

  // copy-assign constructor, increment right, decrement left
  HasPtr &operator=(const HasPtr&hs) {
    ++*hs.use;
    if (--*use == 0) {
      delete ps;
      delete use;
    }

    ps = hs.ps;
    i = hs.i;
    use = hs.use;
    return *this;
  };

  int reference_count() {
    return *use;
  };

  ~HasPtr() {
    --(*use);
    if ( *use == 0) {
      delete ps;
      delete use;
    }
  };
private:
  std::string *ps;
  int i;
  // keep track of how many objects share *ps
  std::size_t *use;
};


TEST(RCTest, SomeTest) {
  HasPtr hs;
  HasPtr hs2(hs);
  HasPtr hs3 = hs2;
  EXPECT_EQ(hs3.reference_count(), 3);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

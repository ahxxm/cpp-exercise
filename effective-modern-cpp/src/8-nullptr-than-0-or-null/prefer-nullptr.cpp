#include "gtest/gtest.h"


void f(int) {}
void f(bool) {}
void f(void *) {}


void ff() {
  f(0);

  // ambiguous, typically calls f(int)
  // if NULL is 0L, conversion o int bool void*
  // is considered equally good
  // f(NULL);

  // nullptr does not have integral type
  // no pointer type either, but "think of it as a pointer of all types"
  // std::nullptr_t FIXME: "wonderful circular definition"
  f(nullptr);
}

TEST(NullptrTest, SomeTest) {
  ff();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

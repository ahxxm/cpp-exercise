#include "gtest/gtest.h"


// constexpr is interface of object/function
// constexpr (conceptually) means value is known during compilation
// applies to VERY SIMPLE and non-virtual function with very simple return type
// constexpr implies const
// http://stackoverflow.com/questions/14116003/difference-between-constexpr-and-const



// constexpr const int *NP = &N;
// both required: constexpr for NP, const for N

// for member function like
// constexpr void f() const;
// const: A const member function is a member function that
// guarantees it will not modify the object
// or call any non-const member functions

constexpr int f() {return 42;}


TEST(ConstexprTest, SomeTest) {
  EXPECT_EQ(f(), 42);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

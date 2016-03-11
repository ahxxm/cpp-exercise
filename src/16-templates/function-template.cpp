#include "gtest/gtest.h"

// template <typename T>
// class/typename are the same
template <class T>
int compare(const T &v1, const T &v2) {
  if (v1 < v2) {
    return -1;
  };

  if (v1 > v2) {
    return 1;
  };

  return 0;
}

// nontype param
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char(&p2)[M]) {
  return strcmp(p1, p2);
};



TEST(FunctionTemplateTest, SomeTest) {
  int f = compare<int>(1, 2);
  EXPECT_EQ(f, -1);

  // deduce param type as template param
  int j = compare(2, 1);
  EXPECT_EQ(j, 1);

  int k = compare(2, 2);
  EXPECT_EQ(k, 0);

  // compare two string literal
  // compiler inserts null terminator, so N is 3, M is 4
  int l = compare("hi", "cpp");
  int ll = compare("hi", "zpp");
  EXPECT_EQ((l > 0), true);
  EXPECT_EQ((ll < 0), true);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include <functional>
#include <string>
#include "gtest/gtest.h"


// template <typename T>
// class/typename are the same
template <class T>
int compare(const T &v1, const T &v2) {
  // less makes it available to compare 2 pointers
  if (std::less<T>()(v1, v2)) {
    return -1;
  }

  // T does not have to support ">" then
  if (std::less<T>()(v2, v1)) {
    return 1;
  }

  return 0;
}

// nontype param
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char(&p2)[M]) {
  return strcmp(p1, p2);
}


// 5: print array
template<typename T>
void print(T const &a) {
  for (auto const &i : a) {
    std::cout << i << std::endl;
  }
}


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

  // 5: print array
  std::string s[] = {"string", "array"};
  char c[] = { 'c', 'h', 'a', 'r' };
  int i[] = { 1 };
  print(s);
  print(c);
  print(i);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

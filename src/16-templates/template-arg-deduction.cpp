#include "gtest/gtest.h"
#include <string>


template <typename T>
T fobj(T a, T) {
  return a;
};

template <typename T>
T fref(const T &a, const T&) {
  return a;
};


// NOTE: non-template param can be implicitly converted
template <class T>
int compare(const T&, const T&) {return 42;};

TEST(DeductionTest, SomeTest) {
  std::string s1("something");
  const std::string s2("else");
  fobj(s1, s1); // calls (string,string), ignore const
  fref(s1, s2); // convert s1 to const

  int a[10], b[42];
  fobj(a, b); // (int *, int *)
  // fref(a, b); // error, type not consistent

  // 34: string literal is basic char *,
  // thus no matching function
  // compare("hi", "world");

  std::string c = "hi";
  std::string d = "world";
  compare(c, d);
  compare("bye", "dad");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
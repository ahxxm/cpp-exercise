#include <string>
#include <utility>
#include <vector>
#include "gtest/gtest.h"


class Widget {
public:
  // origin look: mafan to maintain
  /*
  // copy ref
  void addName(const std::string &name) {
    names.push_back(name);
  }
  // move rval
  void addName(std::string &&name) {
    names.push_back(std::move(name));
  }
  */

  // template: too heavy
  // might yield several functions to convert
  // objects to std::string
  /*
  template<typename T>
  void addName(T &&name) {
    names.push_back(std::forward<T>(name));
  }
  */

  // solution: pass by value
  // efficiency in C++11: rvalue name will be move constructed.
  // limit: move-only objects, cheap operation, only when param
  // is finally to be copied, slicing problem(inherit class)..
  void addName(std::string name) {
    // move is safe: final use, new copied value.
    names.push_back(std::move(name));
  }


private:
  std::vector<std::string> names;
};


TEST(PBVTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

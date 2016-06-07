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

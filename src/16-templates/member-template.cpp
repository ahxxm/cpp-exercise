#include "gtest/gtest.h"
#include <iostream>


class Del {
public:

  Del() = default;

  template <typename T>
  void operator()(T *) const {
    std::cout << "java" << std::endl;
  };
};


TEST(MemberTemplateTest, SomeTest) {
  // call on object
  Del d;
  int j;
  d(&j);

  // on temporary object
  Del()(&j);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include <vector>
#include "gtest/gtest.h"


class Polynomial {
public:
  using RootsType = std::vector<double>;

  RootsType roots() const {
    if( !rootsAreValid ) {
      // compute root
      rootsAreValid = true;
    }
    return rootVals;
  }


private:
  mutable bool rootsAreValid {false};
  mutable RootsType rootVals {};
};



TEST(ConstThreadSafeTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

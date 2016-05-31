#include <vector>
#include "gtest/gtest.h"


// roots() needs to modify mutable fields, should be thread safe
class Polynomial {
public:
  using RootsType = std::vector<double>;

  RootsType roots() const {
    // easiest way: add lock
    // std::lock_guard<std::mutex> g(m);

    // atomic
    // ONLY for one variable, 2 or more can cause headache
    // ++callCount;

    if( !rootsAreValid ) {
      // compute root
      rootsAreValid = true;
    }
    return rootVals;
  }


private:
  // lock
  // mutable std::mutex m;
  // NOTE: std::mutex is move only object, this makes whole class
  // lose ability to be copied.


  // usually less expensive:
  // std::atomic<unsigned>  callCount { 0 };
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

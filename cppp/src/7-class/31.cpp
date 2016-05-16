#include "gtest/gtest.h"


// 31: class X and Y
// X has pointer to Y
// Y has object of type X

// forward declaration
class Y;

class X {
public:
  Y *pointer;
};

class Y {
public:
  X object;
};



TEST(FirstClassExerciseTest, SomeTest) {
  X testX;
  std::cout << &testX << std::endl;

  // not initialized, don't use
  // std::cout << &(testX.pointer->object) << std::endl;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

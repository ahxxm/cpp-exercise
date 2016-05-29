#include "gtest/gtest.h"


bool isLucky(int) {return false;}

// rejects double and floats
// because C++ prefers convert float to double than int
bool isLucky(double) = delete;


TEST(DeletedTest, SomeTest) {

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

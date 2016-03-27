#include "gtest/gtest.h"
#include <string>


// if virtual function can't be used, RTTI operators are viable.
// "The programmer must know to which type the object should be
// cast and must check that the cast was performed successfully."

void cast() {

};


TEST(RTTITest, SomeTest) {
  cast();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <bitset>



TEST(BitsetTest, SomeTest) {
  // low(est)-order bit is 1,others 0
  std::bitset<16> bitvec(1U);

  // access from lowest one, low-order bit
  std::cout << bitvec[0] << std::endl;
  EXPECT_EQ(bitvec[0], 1);
  EXPECT_EQ(bitvec[1], 0);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

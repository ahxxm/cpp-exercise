#include <bitset>
#include "gtest/gtest.h"


TEST(BitsetTest, SomeTest) {
  // low(est)-order bit is 1,others 0
  std::bitset<16> bitvec(1U);

  // access from lowest one, low-order bit
  std::cout << bitvec[0] << std::endl;
  EXPECT_EQ(bitvec[0], 1);
  EXPECT_EQ(bitvec[1], 0);

  // high order bits are discarded
  std::bitset<13> bitvec1(0xbeef);

  // 2 and 3 are 1, others 0
  std::bitset<32> bitvec2("1100");

  // conversions
  std::cout << bitvec1.to_string() << std::endl;
  std::cout << bitvec2.to_string() << std::endl;
  std::cout << bitvec2.to_ullong() << std::endl;

  // more bitset from string
  std::string str("1111111000000011001101");
  std::bitset<32> bitvec5(str, 5, 4); //  four bits starting at str[5], 1100
  std::bitset<32> bitvec6(str, str.size() - 4); // use last four characters



}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

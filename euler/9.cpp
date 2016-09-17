#include "gtest/gtest.h"

// Special Pythagorean triplet
// Definition: a^2+b^2=c+2 (right triangle)

// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

// solution: 200,375
void solve() {
  for(int i = 1;i <= 1000; ++i) {
    for(int j = 1;j <= 1000; ++j) {
      int k = 1000 - i - j;
      if(i * i + j * j == k * k) {
        std::cout << i * j * k<< std::endl;
      }
    }
  }
}



TEST(PythagoreanTripletTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

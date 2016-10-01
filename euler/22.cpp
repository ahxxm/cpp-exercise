#include <string>
#include "gtest/gtest.h"

// TODO: leave for future
// - cpp-netlib not compatible with boost 1.61
// - cpr introduces gtest(cmake conflict) and tests that require
// environment variable BUILD_CPR_TESTS=OFF to disable

// TODO: emacs config to detect its headers

/*

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

*/


TEST(NameScoreTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <string>
#include <vector>

// num to string
using con = std::vector<std::string>;

con digit = {"zero", "one", "two", "three",
             "four", "five", "six", "seven",
             "eight" ,"nine" , "ten", "eleven",
             "twelve", "thirteen", "fourteen",
             "fifteen", "sixteen", "seventeen",
             "eighteen", "nineteen"};
con ten = {"zero", "ten", "twenty", "thirty", "forty",
           "fifty", "sixty", "seventy", "eighty", "nightly"};


int num_to_word_count(int n) {
  if (n < 0) {return -1;}
  if (n == 1000) {return 11;} // one thousand,3+8
  if (n >= 100) {
    int hun = digit[n / 100].size() + 7; // hundred,7
    auto mod = n % 100;
    if (mod == 0) {
      return hun;
    } else {
      // and,3
      return hun + 3 + num_to_word_count(mod);
    }
  } else if (n >= 20) {
    int tens = ten[n / 10].size();
    auto mod = n % 10;
    if (mod == 0) {
      return tens;
    } else {
      return tens + num_to_word_count(mod);
    }
  } else {
    return digit[n].size();
  }
}

int solve() {
  int result = 0;
  for(int i = 1; i <= 1000; ++i) {
    result += num_to_word_count(i);
  }
  return result;
}


TEST(MoreClassExerciseTest, SomeTest) {
  EXPECT_EQ(num_to_word_count(-1), -1);
  EXPECT_EQ(num_to_word_count(19), 8);
  EXPECT_EQ(num_to_word_count(21), 9);
  EXPECT_EQ(num_to_word_count(121), 22);
  std::cout << solve() << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

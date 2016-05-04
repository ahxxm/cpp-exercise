#include <regex>
#include <string>
#include "gtest/gtest.h"


/*
  http://stackoverflow.com/questions/12530406/is-gcc-4-8-or-earlier-buggy-about-regular-expressions/12665408#12665408

TEST(RegexTest, SomeTest) {
  // find ei, that follow a char other than c
  std::string re_pattern("[^c]ei");
  std::string text("ooaeiuuuu");
  std::regex r(re_pattern);

  // only matches string input sequence
  // for char use std::cmatch
  std::smatch results;
  auto result = std::regex_search(text, results, r);
  EXPECT_EQ(result, true);
  // str() equals str(0), the first sub-regex
  // is r itself.
  EXPECT_EQ(results.str(), "aei");

  std::smatch no_results;
  std::string no_result_text("uiiui");
  auto no_result = std::regex_search(no_result_text, no_results, r);
  EXPECT_EQ(no_result, false);
  EXPECT_EQ(no_results.str(), "");

  // error
  try {
    std::regex rre("[[:alm:]+\\.");
    EXPECT_EQ(1, 2); // never reached here
  } catch(std::regex_error e) {
    std::cout << e.what() << "\n" << std::endl;
    EXPECT_EQ(1, 1);
  };

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
*/


int main(int argc, char *argv[]) {

  return 0;
}

#include <string>
#include <vector>
#include "gtest/gtest.h"

// 45: iterator, insert and append
// add prefix and suffix to a string
void add_prefix_suffix(std::string &s, const std::string &prefix, const std::string &suffix) {
  s.insert(s.begin(), prefix.begin(), prefix.end());
  s.append(suffix);
}

// 46: rewrite 45 with only insert
void insert_prefix_suffix(std::string &s, const std::string &prefix, const std::string &suffix) {
  s.insert(s.begin(), prefix.begin(), prefix.end());
  s.insert(s.end(), suffix.begin(), suffix.end());
}

// 50:
int sum_vector_int_string(std::vector<std::string> &va) {
  int result = 0;
  for ( auto i: va ) {
    result += std::stoi(i);
  }

  return result;
}


TEST(MoreClassExerciseTest, SomeTest) {
  std::string st = "string";
  std::string pre = "p";
  std::string suf = "d";
  add_prefix_suffix(st, pre, suf);
  EXPECT_EQ(st, "pstringd");

  std::string st2 = "st";
  insert_prefix_suffix(st2, pre, suf);
  EXPECT_EQ(st2, "pstd");

  std::vector<std::string> vi = {"1234", "123a"};
  int sum = sum_vector_int_string(vi);
  EXPECT_EQ(sum, 1357);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

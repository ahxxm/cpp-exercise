#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>

TEST(MoreContainerTest, SomeTest) {
  std::list<std::string> authors = {"milton", "shakespear"};
  std::vector<const char*> articles = {"a", "an", "the"};

  std::list<std::string> list2(authors);
  // std::deque<std::string> authorList(authors); // no constructor from list to deque
  // std::vector<std::string> words(articles); // same as above
  std::forward_list<std::string> words(articles.begin(), articles.end()); // this is ok: convert const char* to string


  // 11: create and initialize vector
  // 6 ways..
  std::vector<int> v1;
  std::vector<int> v2 = {1};
  std::vector<int> v3 (10); // default initialized ten 0
  std::vector<int> v4 (10, -1);
  std::vector<int> v5 = v4; // copy from v4
  std::vector<int> v6 (v4.cbegin(), v4.cend()); // init from iterator

  // 12: difference between constructor that
  // takes container to copy
  // and takes 2 iterators
  // difference: 2 iterator does not have to be begin and end

  // 13:
  // list<int> to vector<double>
  std::list<int> l1 = {1, 2, 3, 4};
  std::vector<double> vv1(l1.cbegin(), l1.cend());
  EXPECT_EQ(vv1[0], 1.0);

  // vector<int> to vector<double>
  // the same
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

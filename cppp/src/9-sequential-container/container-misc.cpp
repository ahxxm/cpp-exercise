#include <algorithm>
#include <deque>
#include <forward_list>
#include <list>
#include <string>
#include <vector>
#include "gtest/gtest.h"

void create_vector() {
  std::vector<int> v1;
  std::vector<int> v2 = {1};
  std::vector<int> v3 (10);  // default initialized ten 0
  std::vector<int> v4 (10, -1);
  std::vector<int> v5 = v4;  // copy from v4
  std::vector<int> v6 (v4.cbegin(), v4.cend());  // init from iterator
}

void container_convert() {
  std::list<std::string> authors = {"milton", "shakespear"};
  std::vector<const char*> articles = {"a", "an", "the"};

  std::list<std::string> list2(authors);
  // std::deque<std::string> authorList(authors); // no constructor from list to deque
  // std::vector<std::string> words(articles); // same as above
  std::forward_list<std::string> words(articles.begin(), articles.end());  // this is ok: convert const char* to string
}

std::vector<double> list_int_to_vector_double(const std::list<int> &li) {
  std::vector<double> vv1(li.cbegin(), li.cend());
  return vv1;
}

void some_insert() {
  std::list<std::string> slist;
  std::vector<std::string> v = {"quasi", "simba"};
  slist.insert(slist.end(), {"these", "words"});
}

void continuous_insert() {
  std::list<int> jar;
  auto iter = jar.begin();
  for (int i = 0;i <= 10; ++i) {
    iter = jar.insert(iter, i);
  }
}

void access_container(const std::list<int> &vi) {
  // front and back are values
  // begin and end are iterator
  if (!vi.empty()) {
    int val = *vi.begin(), val2 = vi.front();
    auto last = vi.end();  // iterator
    int val3 = *(--last);  // does not support forward_list iterators
    int val4 = vi.back();
    val4 -= (val3 - val * val2);
  }

}


TEST(MoreContainerTest, SomeTest) {
  container_convert();

  // 11: create and initialize vector
  // 6 ways..
  create_vector();

  // 12: difference between constructor that
  // takes container to copy
  // and takes 2 iterators
  // difference: 2 iterator does not have to be begin and end

  // 13:
  // list<int> to vector<double>
  std::list<int> l1 = {1, 2, 3, 4};
  auto vv1 = list_int_to_vector_double(l1);
  EXPECT_EQ(vv1[0], 1.0);

  // vector<int> to vector<double>
  // the same

  // after swap, pointer still points to
  // previous object, though value has changed
  std::vector<double> vv2 = {4, 3, 2, 1};
  std::vector<double> *pl1 = &vv1;
  std::swap(vv1, vv2);
  EXPECT_EQ(*vv1.begin(), 4);
  EXPECT_EQ(*(pl1->begin()), 4);

  // container.insert
  some_insert();
  continuous_insert();

  // container access
  access_container(l1);

  // 9.23: what if l1.size() is 1?
  std::list<int> ltest = {1};
  EXPECT_EQ(ltest.size(), 1);
  EXPECT_EQ(*ltest.begin(), 1);
  EXPECT_EQ(ltest.front(), 1);
  EXPECT_EQ(ltest.back(), 1);
  // one pass end, so -- makes it point to end
  auto last = ltest.end();
  auto val3 = *(--last);
  EXPECT_EQ(val3, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

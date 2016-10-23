#include "gtest/gtest.h"


struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x): val(x), next(nullptr) {}
};



class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *before = nullptr;
    auto iter = head;
    while (iter) {
      auto n = iter->next;
      iter->next = before;
      before = iter;
      iter = n;
    }
    head = iter;
    return head;
  }
};



TEST(ReverseLinkedListTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

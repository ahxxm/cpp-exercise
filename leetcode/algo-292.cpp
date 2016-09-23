#include "gtest/gtest.h"

/*

You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

*/


/*
  heap of stones on the table
  takes turns to remove 1-3 stones(you first)
  winner: remove last one

  win:1 loss:0
1 2 3 4 5 6 7 8 9 10 11 12
1 1 1 0 1 1 1 0 1  1  1  0
 */

using ll = long long;

class Solution {
public:
    bool canWinNim(int n) {
      if(n % 4 == 0) {return false;}
      return true;
    }
};

TEST(NimGameTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

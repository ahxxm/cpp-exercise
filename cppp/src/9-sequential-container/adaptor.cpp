#include <queue>
#include <stack>
#include "gtest/gtest.h"


std::stack<int> some_stack() {
  std::stack<int> intStack;

  for (size_t ix = 0; ix != 10; ++ix) {
    intStack.push(ix);
  }

  while (!intStack.empty()) {
    int value = intStack.top();
    std::cout << value << std::endl;
    intStack.pop();
  }

  return intStack;
}


std::queue<int> some_queue() {
  std::queue<int> que;
  que.push(1);
  que.push(2);
  return que;
}


TEST(AdaptorTest, SomeTest) {
  unsigned int stack_size = 0;
  auto sta = some_stack();
  EXPECT_EQ(sta.size(), stack_size);

  int que_backvalue = 2;
  auto que = some_queue();
  EXPECT_EQ(que.back(), que_backvalue);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

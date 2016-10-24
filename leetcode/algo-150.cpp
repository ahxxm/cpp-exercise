#include <stack>
#include <string>
#include <vector>
#include "gtest/gtest.h"

using vs = std::vector<std::string>;


class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> s;

    for (auto i : tokens) {
      if (isOperator(i)) {
        auto y = s.top();
        s.pop();
        auto x = s.top();
        s.pop();
        s.push(eval(x, y, i));
      } else {
        s.push(std::stoi(i));
      }
    }

    return s.top();
  }

  bool isOperator(const std::string &s) {
    // hard-coded
    return (s == "+" || s == "-" || s == "*" || s == "/");
  }

  int eval(const int &x, const int &y, const std::string &op) {
    if (op == "+") {
      return x + y;
    }
    else if (op == "-") {
      return x - y;
    }
    else if (op == "*") {
      return x * y;
    }
    else {
      return x / y;
    }
  }
};


TEST(EvalRPNTest, SomeTest) {
  EXPECT_EQ(std::stoi("13"), 13);
  auto a = Solution();
  vs x = {"2", "1", "+", "3", "*"};
  vs y = {"4", "13", "5", "/", "+"};
  EXPECT_EQ(a.evalRPN(x), 9);
  EXPECT_EQ(a.evalRPN(y), 6);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

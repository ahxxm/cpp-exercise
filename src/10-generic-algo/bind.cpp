#include "gtest/gtest.h"
#include <functional>
#include <string>

bool isLonger(std::string &s, std::size_t sz) {
  return s.size() > sz;
}

TEST(BindTest, SomeTest) {
  auto newIsLonger = std::bind(isLonger, std::placeholders::_1, 2);
  std::string st = "12345";
  EXPECT_EQ(newIsLonger(st), true);

  // Bind can re-arrange param
  auto rearrangedLongerThanTwo = std::bind(isLonger, std::placeholders::_2, std::placeholders::_1);
  EXPECT_EQ(rearrangedLongerThanTwo(2, st), true);

  // bind copies value,
  // cref()/ref() makes it reference
  // _2 means param's origin position in isLonger was 2
  auto refBindLonger = std::bind(isLonger, std::ref(st), std::placeholders::_2);
  EXPECT_EQ(refBindLonger(st, 4), true);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

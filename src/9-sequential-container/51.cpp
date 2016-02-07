#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include "time.h"

class BasicDate {
public:
  unsigned int year = 0;
  unsigned int month = 0;
  unsigned int day = 0;

  BasicDate() {
    // FIXME: default initialize as now
    std::time_t tt = std::time(NULL);
    std::string result = asctime(gmtime(&tt));
    std::cout << result << std::endl;
  };

  // FIXME: handle different format
  //
  BasicDate(const std::string &datestr) {

  }
private:

};



TEST(BasicDateTest, SomeTest) {
  auto dd = BasicDate();
  EXPECT_EQ(dd.year >= 2015, 1);

  std::string d1 = "1993-01-01";
  std::string d2 = "Jan 1,1993";
  auto dd1 = BasicDate(d1);
  EXPECT_EQ(dd1.year, 1993);
  EXPECT_EQ(dd1.month, 1);
  EXPECT_EQ(dd1.day, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

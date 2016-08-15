#include <ctime>
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include "time.h"
#include "gtest/gtest.h"

class BasicDate {
public:
  unsigned int year = 0;
  unsigned int month = 0;
  unsigned int day = 0;

  BasicDate() {
    // default unix time, of type long
    std::time_t tt = std::time(nullptr);

    // set year
    auto localtime = std::localtime(&tt);
    year = localtime->tm_year + 1900;  // years since 1900
    month = localtime->tm_mon;
    day = localtime->tm_mday;
    std::cout << "year" << year << " month" << month << std::endl;

  };

  explicit BasicDate(const std::string &) {

  }
private:
};



TEST(BasicDateTest, SomeTest) {
  auto dd = BasicDate();
  EXPECT_EQ(dd.year >= 2015, 1);

  // std::string d1 = "1993-01-01";
  // std::string d2 = "Jan 1,1993";
  // auto dd1 = BasicDate(d1);
  // EXPECT_EQ(dd1.year, 1993);
  // EXPECT_EQ(dd1.month, 1);
  // EXPECT_EQ(dd1.day, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

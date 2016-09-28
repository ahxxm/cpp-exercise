#include <vector>
#include "gtest/gtest.h"


/*

  You are given the following information, but you may prefer to do some research for yourself.

  1 Jan 1900 was a Monday.

  Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.

  A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

  How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

// convert to count weeks:
//
using vi = std::vector<int>;

int weekday(int year, int month, int day) {
  // Zeller's Congruence of Gregorian calendar
  // month: Jan 13, Feb 14, March 3
  // result: 0 Sat, 1 Sun, 2 Mon, 3 Tue, 4 Wed, 5 Thu, 6 Fri
  int __month = month < 3 ? month + 12 : month;
  int y = year % 100;
  int y4 = y / 4;
  int c = year / 100;
  int c4 = c / 4;
  int m = 13 * (__month + 1) / 5;
  return (day + m + y + y4 + c4 + 5 * c) % 7;
}

int solve() {
  int days = 0;
  for (int y = 1901; y <= 2000; ++y) {
    for (int m = 1; m <= 12; ++m) {
      if (weekday(y, m, 1) == 1) {
        days += 1;
      }
    }
  }
  return days;
}


TEST(SundayCountTest, SomeTest) {
  std::cout << solve() << std::endl;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

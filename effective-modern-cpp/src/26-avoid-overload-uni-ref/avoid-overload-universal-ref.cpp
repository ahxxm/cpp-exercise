// #include <chrono>
#include <string>
#include <utility>
#include <set>
#include "gtest/gtest.h"



std::multiset<std::string> names {};


template<typename T>
void logAndAdd(T &&name) {
  // universal ref move emplace instead of copy

  // auto now = std::chrono::system_clock::now();
  // log(now);

  names.emplace(std::forward<T>(name));
}


TEST(OverloadUniversalRefTest, SomeTest) {
  std::string pet = {"Darla"};
  logAndAdd(pet);

  logAndAdd(std::string("wut"));

  logAndAdd("dog");

  // logAndAdd(22);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

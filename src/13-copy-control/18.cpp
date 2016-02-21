#include "gtest/gtest.h"
#include <string>
#include <iostream>

// 18: string constructor
class Employee {
public:
  static int n;
  Employee() = delete;
  Employee(const std::string &s): currentID(n++) {
    name = s;
  }

  int id() {
    return currentID;
  }

private:
  std::string name;
  const int currentID;
};

int Employee::n = 42;

TEST(UniqueTest, SomeTest) {
  auto a = Employee("ja");
  auto b = Employee("va");
  EXPECT_EQ((a.id() == b.id()), false);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

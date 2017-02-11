#include <iostream>
#include <string>
#include "gtest/gtest.h"

// 18: string constructor
class Employee {
public:
  static int n;
  Employee() = delete;
  explicit Employee(const std::string &s):
    name(s), currentID(n++) {}

  // 19: copy-control members
  // new Emploee with same name, but different id
  Employee(const Employee &): currentID(n++){ };

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
  auto c = Employee(b);
  EXPECT_EQ((a.id() == b.id()), false);
  EXPECT_EQ((a.id() == c.id()), false);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <string>


// pointer to static member are ordinary pointers

// pointer to members
class Screen {
public:
  typedef std::string::size_type pos;
  char get_cursor() const { return contents[cursor]; }
  char get() const;
  char get(pos ht, pos wd) const;
  std::string func() {return datap;};
  std::string datap {"a string"};
private:
  std::string contents; pos cursor;
  pos height, width;
};


TEST(MemberPointerTest, SomeTest) {
  // pointer to data members
  // pdata can point to a string member of Screen
  // std::string Screen::*pdata;
  Screen a;
  auto pdata = &a.datap;
  std::cout << *pdata << std::endl;
  EXPECT_EQ(*pdata, "a string");

  // pointer to member functions
  // const function requires const pointer
  auto pmf = &Screen::func;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

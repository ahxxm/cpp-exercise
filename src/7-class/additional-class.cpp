#include "gtest/gtest.h"
#include <string>
#include <vector>

class Screen {
  // Represent a window in display
public:
  // type member using local: must appear before used
  // using pos = std::string::size_type; // c++ 11
  typedef std::string::size_type pos;

  // 24: 3 constructors
  Screen() = default;
  Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {};
  Screen(pos ht, pos wd, std::string c): height(ht), width(wd), contents(c) {};

  // Charactor at cursor
  char get() const {
    {return contents[cursorPosition];}
  };
  inline char get(pos r, pos c) const;

  Screen &move(pos r, pos c) ;

  pos *some_member() const {
    ++access_count;
    return &access_count;
  };

private:
  mutable pos cursorPosition;
  mutable pos access_count;
  pos height;
  pos width;
  std::string contents;


};

class WindowMgr {
public:
  Screen::pos wut;
private:
  std::vector<Screen> screens {Screen(24, 80, ' ')};
};



TEST(AdditionalClassTest, SomeTest) {
  Screen new_empty_screen = Screen();
  std::string::size_type *count = new_empty_screen.some_member();
  EXPECT_EQ(*count, 1);
  // EXPECT_EQ((std::string)new_empty_screen.get(),  "");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

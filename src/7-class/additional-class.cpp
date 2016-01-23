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

  inline Screen &set(char c) {
    contents[cursorPosition] = c;
    return *this;
  };
  inline Screen &set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
  }


  Screen &move(pos r, pos c) ;

  pos *some_member() const {
    ++access_count;
    return &access_count;
  };

  // even do_display is const, this public function
  // returns non-const reference.
  // This way result can use fluent style calling.
  Screen &display(std::ostream &os) {
    do_display(os);
    return *this;
  }

  const Screen &display(std::ostream &os) const {
    do_display(os);
    return *this;
  }

private:
  mutable pos cursorPosition;
  mutable pos access_count;
  pos height;
  pos width;
  std::string contents;

  void do_display(std::ostream &os) const {
    os << contents;
  }


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

  // set first element to 1 and display whole screen
  Screen not_empty_screen = new_empty_screen.set('1').display(std::cout);
  EXPECT_EQ(not_empty_screen.get(), '1');
  EXPECT_EQ(new_empty_screen.get(), '1');
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

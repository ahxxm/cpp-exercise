#include <string>
#include <vector>
#include <iostream>
#include "gtest/gtest.h"


class Screen {

  // Window_mgr can access private parts
  friend class WindowMgr;

  // or make single function friend..
  // requires careful structuring of program to accomodate
  // interdependencies among declarations and definitions.
  // 1. define Window_mgr class, which declars clear().
  // 2. define Screen, include friend clear().
  // 3. define clear().
  // friend void WindowMgr::clear(Sc); // exercise 32

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
    // can't set [0] to a char on string of size 0
    if (contents.size() == cursorPosition) {
      contents += c;
    } else {
      contents[cursorPosition] = c;
    }
    return *this;
  };
  inline Screen &set(pos r, pos col, char c) {
    contents[r * width + col] = c;
    return *this;
  }


  Screen &move(pos r, pos c);

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

  // 7.34: this line shouldn't be put in the last line of class
  // or unknown type will be raised during compilation
  typedef std::vector<Screen>::size_type ScreenIndex;

  // clear single screen
  void clear() {
    single_screen.contents = std::string(single_screen.height * single_screen.width, ' ');
  };
  void clear(ScreenIndex);

  ScreenIndex addScreen(const Screen &s);

  // reference type 'Screen &' would not be initialized
  // WindowMgr() = default;
  explicit WindowMgr(Screen &s): single_screen(s) {};

private:
  Screen &single_screen;
  std::vector<Screen> screens {Screen(24, 80, ' ')};
};

// add screen method outside definition
// scope inside braces is the same as in definition
// but return type is not.(7.33)
WindowMgr::ScreenIndex WindowMgr::addScreen(const Screen &s) {
  screens.push_back(s);
  return screens.size() - 1;
}

// visit private contents
void WindowMgr::clear(ScreenIndex i) {
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}



TEST(AdditionalClassTest, SomeTest) {
  Screen new_empty_screen = Screen();
  std::string::size_type *count = new_empty_screen.some_member();
  std::string::size_type count_one = 1;
  EXPECT_EQ(*count, count_one);

  // set first element to 1 and display whole screen
  Screen not_empty_screen = new_empty_screen.set('1').display(std::cerr);
  EXPECT_EQ(not_empty_screen.get(), '1');

  not_empty_screen.display(std::cerr);
  std::cout << std::endl;

  EXPECT_EQ(new_empty_screen.get(), '1');

  // clear this screen's content
  WindowMgr wm = WindowMgr(not_empty_screen);
  wm.clear();
  EXPECT_EQ(not_empty_screen.get() == '1', 0);

  // scope
  Screen::pos a = 20;
  EXPECT_EQ(static_cast<int>(a), 20);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

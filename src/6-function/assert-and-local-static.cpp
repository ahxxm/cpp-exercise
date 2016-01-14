#include <cassert>
#include <iostream>

int debug_features(int argc, char *argv[]) {
  // `assert` is preprocessor marco, so no std::, and its name should be
  // unique.
  // behavior of `assert` depends on NDEBUG, if NDEBUG is defined, assert
  // does nothing.
  int NDEBUG = 1;
  assert(1 == 1);
  assert(1 != 0);

  // local static defined by compiler, function name, array of const char
  std::cout << __func__ << std::endl;
  std::cout << *__func__ << std::endl;

  // __FILE__: filename
  // __LINE__: current line number
  // __TIME__ , __DATE__: compiled time and date
  std::cout << "File: " << __FILE__ << " compiled at: "
            << __DATE__ << " " << __TIME__ << std::endl;

  std::cout << "Current line is: " << __LINE__ << std::endl;

  return 0;
}

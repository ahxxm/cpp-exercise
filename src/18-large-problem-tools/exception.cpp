#include "gtest/gtest.h"
#include <exception>
#include <string>

void catch_all() {
  try {
    throw std::logic_error("intended error");
  } catch(...) {
    std::cout << "caught!" << std::endl;
  };
};

template <class T>
class Foo {
public:
  Foo() = default;
  Foo(std::string);

  std::string ii;
};

// catch with initializer
// FIXME: does not caught "hi"
template <typename T>
Foo<T>::Foo(std::string i)
  try: ii(i) {
    if (ii != "hello") {
      std::cout << "caught: " << i << std::endl;
      throw std::logic_error("only accept `hello`.");
    };
    } catch(const std::logic_error &){
    ii = "hello";
  };


// `noexcept` specification: nonthrowing
// noexcept or noexcept(bool)
template <typename T>
void nothing(T&&) noexcept(true) {};



TEST(ExceptionTest, SomeTest) {
  catch_all();
  auto i = Foo<int> ("hello");
  // auto j = Foo<int> ("hi");
  EXPECT_EQ(i.ii, "hello");
  // EXPECT_EQ(j.ii, "hello");

  nothing("jar");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

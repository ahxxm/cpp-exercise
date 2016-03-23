#include "gtest/gtest.h"
#include <exception>

void catch_all() {
  try {
    throw std::logic_error("intended error");
  } catch(...) {
    std::cout << "caught!" << std::endl;
  };
};


TEST(ExceptionTest, SomeTest) {
  catch_all();
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include <iostream>

// fstream: file stream
// - ifstream: read file
// - ofstream: write to file
// - fstream: both


void open(const std::string &filename) {
  // will try to open `filename` under
  // same directory of compiled file
  std::ifstream in(filename);
  in.close();
  std::ofstream out;
  out.open(filename + ".copy");

  // so `out` will be under `build/`
  if (out) {
    std::cout << "java" << std::endl;
  } else {
    std::cout << "java failed" << std::endl;
  }
  // close is called automatically when
  // `out` is destroyed
  out.close();
};


TEST(MoreClassExerciseTest, SomeTest) {
  open("test.txt");
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

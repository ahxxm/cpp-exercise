#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

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
  }
  // close is called automatically when
  // `out` is destroyed
  out.close();
};

// 8: append content to file
void append_to_file(std::string filename, std::string content) {
  // explicit out+appending mode
  // by default ofstream truncates exising content.
  // std::ofstream app(filename, std::ofstream::out | std::ofstream::app);

  // or when open
  std::ofstream out;
  out.open(filename, std::ofstream::app);
  out << content;
  out.close();
}


// 8.5 rewrite 8.4 to store each word separately
std::string read_file(std::string filename) {
  std::stringstream buffer;
  std::ifstream input(filename);

  buffer << input.rdbuf();
  std::string content = buffer.str();
  return content;
}

// 8.4: read list of files' contents
// into vector
// 10.29
// http://stackoverflow.com/questions/195323/what-is-the-most-elegant-way-to-read-a-text-file-with-c
std::vector<std::string> read_files(std::vector<std::string> filenames) {
  std::vector<std::string> contents;

  for (unsigned long i = 0; i != filenames.size(); ++i) {
    std::string filename = filenames[i];
    std::string content = read_file(filename);
    contents.push_back(content);
  }

  return contents;
};


TEST(MoreClassExerciseTest, SomeTest) {
  open("test.txt");
  append_to_file("test.txt", "something\n");

  std::vector<std::string> filenames;
  std::vector<std::string> contents;
  filenames.push_back("test.txt");
  contents = read_files(filenames);
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

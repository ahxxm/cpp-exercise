#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <set>

class TextQuery {
public:
  TextQuery() = default;

  // FIXME: initialize word_line_map
  TextQuery(std::ifstream &infile) {

  };

  std::string query(const std::string &s) {
    // FIXME:
    std::string result = s;
    return result;
  }
private:
  // word->(line1,line2)
  std::map<std::string, std::set<int>> word_line_map;
};


void runQueries(std::ifstream &infile) {
  // store the file and build query map
  // map(word, (line_set))
  TextQuery tq(infile);


  while (true) {
    std::cout << "Enter the world to look for, or q to quit:" << std::endl;
    std::string s;

    if (!(std::cin >> s) || s == "q") {
      break;
    }

    std::cout << tq.query(s) << std::endl;
  }

}



TEST(QueryTest, SomeTest) {
  // FIXME: test this?
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

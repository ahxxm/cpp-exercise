#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <set>


class QueryResult;

class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;

  TextQuery() = default;
  TextQuery(std::ifstream &infile): file(new std::vector<std::string>){
    std::string text;
    // FIXME: getline no matching function
    while (std::getline(infile, text)) {
      // read file into vector line by line
      file->push_back(text);
      int cur_line = file->size() - 1;

      // read this line word by word
      // insert line_number to its value in map
      std::istringstream line(text);
      std::string word;
      while (line >> word) {
        auto &lines = word_line_map[word];
        if (!lines) {
          lines.reset(new std::set<line_no>);
        }
        lines->insert(cur_line);
      }
    }
  };

  // FIXME:
  QueryResult query(const std::string &) const;
private:
  // input file
  std::shared_ptr<std::vector<std::string>> file;

  // word->(line1,line2)
  std::map<std::string, std::shared_ptr<std::set<line_no>>> word_line_map;
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

    //
    // std::cout << tq.query(s) << std::endl;
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

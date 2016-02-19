#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <set>

using line_no = std::vector<std::string>::size_type;
class QueryResult;

class TextQuery {
public:
  TextQuery() = default;
  TextQuery(std::ifstream &infile): file(new std::vector<std::string>){
    std::string text;
    while (std::getline(infile, text)) {
      // FIXME: getline no matching function
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

  QueryResult query(const std::string &) const;

private:
  // input file
  std::shared_ptr<std::vector<std::string>> file;

  // word->(line1,line2)
  std::map<std::string, std::shared_ptr<std::set<line_no>>> word_line_map;
};


class QueryResult {
  friend std::ostream &print(std::ostream &os, const QueryResult &qr) {
    // print count and each line
    os << qr.sought << " occurs " << qr.lines->size() << " time(s)." << std::endl;
    for (line_no num: *qr.lines) {
      os << "\t(line " << num + 1 << ") "
         << *(qr.file->begin() + num) << std::endl;
    }
    return os;
  }

public:
  QueryResult(std::string s,
              std::shared_ptr<std::set<line_no>> p,
              std::shared_ptr<std::vector<std::string>> f):
    sought(s), lines(p), file(f) {};

private:
  std::string sought;
  std::shared_ptr<std::set<line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;

};

QueryResult TextQuery::query(const std::string &keyword) const {
  // if no data if found..
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

  auto loc = word_line_map.find(keyword);
  if (loc == word_line_map.end()) {
    return QueryResult(keyword, nodata, file);
  } else {
    // second is line_no set
    return QueryResult(keyword, loc->second, file);
  }

}


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

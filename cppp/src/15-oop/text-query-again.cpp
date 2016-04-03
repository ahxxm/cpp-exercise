#include "gtest/gtest.h"
#include <string>
#include <vector>


class QueryResult;
class TextQuery;

class Query_base {
  friend class Query;
protected:
  using line_no = std::vector<std::string>::size_type;
  virtual ~Query_base() = default;
private:
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual std::string rep() const = 0;
};


TEST(MoreTextQueryTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

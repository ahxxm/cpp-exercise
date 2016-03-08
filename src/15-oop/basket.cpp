#include "gtest/gtest.h"
#include <memory>
#include <set>
#include <iostream>


struct Quote {
  std::string isbn() {
    return isbnNo;
  };
private:
  std::string isbnNo;
};

// pointers impose complexity
// define "auxiliary" classes to help manage

class Basket {
public:
  void add_item(const std::shared_ptr<Quote> &qo) {
    items.insert(qo);
  };

  double total_receipt(std::ostream &) const;

private:
  static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  };

  // multiset<element type, comparison function pointer>
  // and initialize items using compare function
  // FIXME: what happened when initializing...
  std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items {compare};
};


TEST(BasketTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

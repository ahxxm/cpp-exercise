#include "gtest/gtest.h"
#include <memory>
#include <set>
#include <iostream>
#include <memory>


struct Quote {
  std::string isbn() {
    return isbnNo;
  };

  virtual Quote* clone() const & {
    return new Quote(*this);
  };

  virtual Quote* clone() && {
    return new Quote(std::move(*this));
  }

private:
  std::string isbnNo;
};

// pointers impose complexity
// define "auxiliary" classes to help manage

class Basket {
public:
  // copy
  void add_item(const Quote& qo) {
    items.insert(std::shared_ptr<Quote>(qo.clone()));
  };

  // move
  void add_item(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  }

  double total_receipt(std::ostream &os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin();iter != items.cend(); iter = items.upper_bound(*iter)) {
      // upper_bound skips all elements that has same key value with iter
      sum += print_total(os, **iter, items.count(*iter));
    };
    os << sum << std::endl;
    return sum;
  };

  // FIXME:
  double print_total(std::ostream &os,const Quote &, int) const {
    return 0.0;
  };

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

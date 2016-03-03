#include "gtest/gtest.h"
#include <stdexcept>

class V {
public:
  virtual int answer() const {
    throw std::exception();
  };

  virtual int bind() {
    return 1;
  }
};

class VV: public V {
public:
  // override with definition requires previous definition
  int answer() const override {
    return 42;
  };

  // also requires virtual function
  // so to use dynamic bind, a virtual base function is
  // required..
  int bind() override {
    return 2;
  }

  int a;
};

int dynamic(V &v) {
  return v.bind();
}


TEST(VirtualFunctionTest, SomeTest) {
  VV a;
  VV b;
  V c;
  EXPECT_EQ(a.answer(), 42);

  EXPECT_EQ(dynamic(a), 2);
  EXPECT_EQ(dynamic(b), 2);
  EXPECT_EQ(dynamic(c), 1);

}


class Quote {
public:

  Quote() = default;
  Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price) {};

  std::string isbn() const {return bookNo;};

  virtual double net_price(std::size_t n) const {
    return n * price;
  };

  // base class almost always define a virtual destructor
  virtual ~Quote() = default;

private:
  std::string bookNo;
protected:
  // derived class can't access private memeber
  // but can access protected one
  double price = 0.0;
};

class BulkQuote: public Quote {
  // inherits public, so it must override net_price
public:
  BulkQuote() = default;
  BulkQuote(const std::string &, double, std::size_t, double) {};

  double net_price(std::size_t) const override;
private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};


TEST(QuoteTest, SomeTest) {
  Quote quote;
  BulkQuote bulk;
  // FIXME: does not work in clang 7.0.2..
  // Quote &r = bulk; // points to Quote part of bulk
};


int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

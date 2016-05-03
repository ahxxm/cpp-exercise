#include <stdexcept>
#include "gtest/gtest.h"


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

  int answer;
  try {
    answer = c.answer();
  } catch (std::exception) {
    answer = 0;
  };
  EXPECT_EQ(answer, 0);
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
  // because sometimes base class pointer points to derived
  // instance, dynamic binding makes destructor smart
  virtual ~Quote() = default;

private:
  std::string bookNo;
protected:
  // derived class can't access private memeber
  // but can access protected one
  double price = 0.0;
};

// only class name is needed in declaration
// no `: public Quote`
class BulkQuote;

class BulkQuote final: public Quote {
  // final means it can't be inherited from
  // inherits public, so it must override net_price
public:
  BulkQuote() = default;
  BulkQuote(const std::string &, double, std::size_t, double) {};

  double net_price(std::size_t amount) const override {
    // virtual function override requires definition
    auto execution_price = amount > min_qty ? discount : price;
    return execution_price * amount;
  };
private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};


TEST(QuoteTest, SomeTest) {
  Quote quote;
  BulkQuote bulk;
  Quote &r = bulk;  // points to Quote part of bulk
  double money = quote.net_price(0);
  double money_2 = r.net_price(0);
  EXPECT_EQ(money, 0);
  EXPECT_EQ(money_2, 0);
};


int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

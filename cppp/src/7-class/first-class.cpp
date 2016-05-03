#include <iostream>
#include <string>
#include "gtest/gtest.h"


// 17: Only different between struct and class: default access level
// only when all members are public we use struct, otherwise
// use class and specifier
// 18: public/private makes a class encapsulated.
class Sales_data {
public:
  // bookNo implicitly refer to member of itself
  // const: const member function, `this` points to const, can't
  // change bookNo by access isbn().
  // call translated: Sales_data::isbn(&instance)
  // rewrite: return this->bookNo;
  std::string isbn() const {return bookNo;};

  double avg_price() const;

  Sales_data &combine(const Sales_data&);
  Sales_data add(const Sales_data&, const Sales_data&);
  std::ostream &print(std::ostream&, const Sales_data&);
  std::istream &read(std::istream&, Sales_data&);

  // constructor
  // Sales_data() = default; // only because we want to provide other constructors

  // delegating constructor:
  // use constructor from its own class body
  Sales_data(): Sales_data("", 0, 0) {
    // 41: print message when constructor used.
    std::cout << "Delegated default constructor used." << std::endl;
  };

  // normal constructor..
  // 47: here `explicit` could be cumbersome when creating
  // temporary instance.
  Sales_data(const std::string &s): bookNo(s) {
    std::cout << "Single bookNo constructor used." << std::endl;

  };

  // only applies to constructors that can be called with
  // a single argument.
  // because other constructors can't perform implicit conversion.
  explicit Sales_data(std::istream &is) {
    read(is,* this);
  };

  Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {
    std::cout << "Complex (bookNo, unit sold, revenue) constructor used." << std::endl;

  };

private:
  // even defined after isbn(), it can be used, because:
  // compiler process member declarations first,
  // then member functions if any.
  std::string bookNo;

  unsigned units_sold = 0;
  double revenue = 0.0;
};

double Sales_data::avg_price() const {
  // this will be interpreted as being inside scope of that class
  if (units_sold) {
    return revenue / units_sold;
  } else {
    return 0;
  }
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  this->units_sold += rhs.units_sold;
  this->revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}


// 4: a Person class for later usage
// 19: seperate private/public,
class Person {
public:
  // 5: return name and address
  // why not const: could change over time
  std::string name() {return Name;};
  std::string address() {return Address;};

  // 15: constructor
  Person() = default;
  Person(const std::string &n): Name(n) {};

private:
  std::string Name;
  std::string Address;
};

TEST(ClassIntroTest, SomeTest) {
  Person empty_person = Person();
  EXPECT_EQ(empty_person.name(), "");

  Sales_data empty_sd = Sales_data();
  EXPECT_EQ(empty_sd.isbn(), "");

  // book sold
  std::string bookName = "test";
  Sales_data sd1 = Sales_data(bookName, 5, 10.0);
  Sales_data sd2 = Sales_data(bookName, 5, 20.0);
  Sales_data sd_combined = add(sd1, sd2);
  EXPECT_EQ(sd_combined.avg_price(), 15.0);

  // no book sold
  Sales_data sd3 = Sales_data(bookName, 0, 10.0);
  Sales_data sd4 = Sales_data(bookName, 0, 20.0);
  Sales_data sd_combined_2 = add(sd3, sd4);
  EXPECT_EQ(sd_combined_2.avg_price(), 0);

  // will initialize a temporary Sales_data from this
  // null_book string, then pass to combine.
  double avg_price;
  avg_price = sd3.avg_price();
  std::string null_book = "111-1-1-1-111";
  sd3.combine(null_book);
  EXPECT_EQ(sd3.avg_price(), avg_price);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <string>

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

  Sales_data &combine(const Sales_data&);
  Sales_data add(const Sales_data&, const Sales_data&);
  std::ostream &print(std::ostream&, const Sales_data&);
  std::istream &read(std::istream&, Sales_data&);

  // constructor
  Sales_data() = default; // only because we want to provide other constructors
  Sales_data(const std::string &s): bookNo(s) {};
  Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {};

private:
  // even defined after isbn(), it can be used, because:
  // compiler process member declarations first,
  // then member functions if any.
  std::string bookNo;
  double avg_price() const;

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
// FIXME: 19 seems redundant..
class Person {
public:
  // 5: return name and address
  // why not const: could change over time
  std::string name() {return Name;};
  std::string Address() {return address;};

  // 15: constructor
  Person() = default;
  Person(const std::string &n): Name(n) {};

private:
  std::string Name;
  std::string address;
};

TEST(ClassIntroTest, SomeTest) {
  Person empty_person = Person();
  EXPECT_EQ(empty_person.name(), "");

  Sales_data empty_sd = Sales_data();
  EXPECT_EQ(empty_sd.isbn(), "");
  // FIXME: expect raise?
  // FIXME: more test: avg_price, combine, add
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

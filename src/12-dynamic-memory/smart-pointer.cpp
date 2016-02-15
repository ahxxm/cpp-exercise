#include "gtest/gtest.h"
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>


class StrBlob {
public:
  typedef std::vector<std::string>::size_type size_type;

  // default constructor: empty vector
  // initializer_list constructor: copy from values in list
  StrBlob(): data(std::make_shared<std::vector<std::string>>()) {};
  StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {};

  size_type size() const {
    return data->size();
  }

  bool empty() const {
    return data->empty();
  }

  void push_back(const std::string &t) {
    data->push_back(t);
  }
  void pop_back() {
    check(0, "pop_back() called on empty StrBlob.");
    data->pop_back();
  };

  // element access
  std::string &front() {
    check(0, "front() called on empty StrBlob.");
    return data->front();
  };
  std::string &back() {
    check(0, "back() called on empty StrBlob.");
    return data->back();
  };

  // 2: const front and back
  const std::string cfront() {
    check(0, "cfront() called on empty StrBlob.");
    const std::string i = data->front();
    return i;
  };

  const std::string cback() {
    check(0, "cback() called on empty StrBlob.");
    const std::string i = data->back();
    return i;
  };

private:
  // this `data` keeps track of how many StrBlob(s)
  // share the same vector...
  std::shared_ptr<std::vector<std::string>> data;

  // throw msg if data[i] isn't valid..
  // 4, Q: why ignore negative check?
  // A: because it's unsigned long, negative will become large number.
  void check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
      throw std::out_of_range(msg);
    }
  };
};



TEST(SmartPointerTest, SomeTest) {
  // type is std::shared_ptr<int>
  auto p = std::make_shared<int>(42);
  *p = 22;
  EXPECT_EQ(*p, 22);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

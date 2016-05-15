#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <exception>
#include <list>
#include "gtest/gtest.h"


class StrBlobPtr;
class StrBlob {
  friend class StrBlobPtr;
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

// holds:
// - (weak)pointer to one vector in a StrBlob
// - current index of that vector
class StrBlobPtr {
public:

  // initialize wptr as nullptr by default..
  StrBlobPtr(): curr(0) {};
  StrBlobPtr(StrBlob &b, std::size_t sz = 0): wptr(b.data), curr(sz) {};


  std::string &deref() const {
    auto p = check(curr, "derefence past end");
    return (*p)[curr];
  };

  std::string &operator*() const {
    return this->deref();
  };

  StrBlobPtr &incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
  };

  StrBlobPtr &operator++() {
    return this->incr();
  };

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t s, const std::string &st) const {
    auto ret = wptr.lock();
    if (!ret) {
      throw std::runtime_error("unbound StrBlobPtr");
    }
    if (s >= ret->size()) {
      throw std::out_of_range(st);
    }
    return ret;
  };
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

void process(std::shared_ptr<int> ptr) {
  std::cout << *ptr << std::endl;
}


TEST(SmartPointerTest, SomeTest) {
  // type is std::shared_ptr<int>
  auto p = std::make_shared<int>(42);
  *p = 22;
  EXPECT_EQ(*p, 22);

  // get() returns a built-in pointer..
  // must not delete this pointer
  int *pp = p.get();
  EXPECT_EQ(*pp, 22);

  auto i = StrBlob();
  EXPECT_EQ(i.size(), 0);
  i.push_back("java");
  EXPECT_EQ(i.cfront(), "java");
  EXPECT_EQ(i.cback(), "java");

  // dangling pointer
  int *j(new int(1024));
  auto k = j;  // k and j points to same memory
  delete j;  // now k become dangling
  k = nullptr;  // indicate k no longer bound to object
  delete k;
  // process(std::shared_ptr<int> (j));

  // Ptr
  std::initializer_list<std::string> ii {"123", "456", "789"};
  StrBlob blob(ii);
  auto blob_ptr = StrBlobPtr(blob);
  EXPECT_EQ(blob_ptr.deref(), "123");
  blob_ptr.incr();
  EXPECT_EQ(blob_ptr.deref(), "456");
  ++blob_ptr;
  EXPECT_EQ(blob_ptr.deref(), "789");
  EXPECT_EQ(*blob_ptr, "789");
};

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

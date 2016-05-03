#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "gtest/gtest.h"


class StrVec {
public:
  StrVec(): first(nullptr), first_free(nullptr), cap(nullptr) {};

  StrVec(const StrVec&s) {
    auto newdata = alloc_and_copy(s.begin(), s.end());
    first = newdata.first;
    first_free = newdata.second;
    cap = newdata.second;
  };

  StrVec &operator=(const StrVec&s) {
    free();

    auto data = alloc_and_copy(s.begin(), s.end());
    first = data.first;
    first_free = data.second;
    return *this;
  };

  ~StrVec() {free();};

  void push_back(const std::string &s) {
    check_and_alloc();
    alloc.construct(first_free++, s);
  };

  std::size_t size() const {
    return first_free - first;
  };

  std::size_t capacity() const {
    return cap - first;
  };

  std::string *begin() const {
    return first;
  };

  std::string *end() const {
    return first_free;
  };

private:
  std::allocator<std::string> alloc;

  void check_and_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }

  // return pointer to begin and one past the last
  // of newly allocated space
  std::pair<std::string*, std::string*> alloc_and_copy(const std::string *begin, const std::string *end) {
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
  };

  // destroy elements and deallocate memory space
  void free() {
    if (first) {
      for (auto p = first_free; p != first; ) {
        alloc.destroy(--p);
      }
      alloc.deallocate(first, cap - first);
    }
  };

  // allocate, construct, destroy
  // here std::move frees old memory
  void reallocate() {
    auto new_cap = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(new_cap);

    auto dest = newdata;
    auto elem = first;
    for (size_t i = 0; i != size(); ++i) {
      alloc.construct(dest++, std::move(*elem++));
    }

    free();

    first = newdata;
    first_free = dest;
    cap = first + new_cap;

  };

  std::string *first;
  std::string *first_free;
  std::string *cap;
};

TEST(StrVecTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

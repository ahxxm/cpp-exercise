#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <memory>


class StrVec {
public:
  StrVec(): first(nullptr), first_free(nullptr), cap(nullptr) {};
  StrVec(const StrVec&);
  StrVec &operator=(const StrVec&);
  ~StrVec();

  void push_back(const std::string&);
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

  std::pair<std::string*, std::string*> alloc_and_copy(const std::string*, const std::string*);

  void free();
  void reallocate();

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

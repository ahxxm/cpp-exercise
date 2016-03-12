#include "gtest/gtest.h"


template <typename T>
class BlobPtr {
public:
  BlobPtr(): curr(0) {};

  // one exception when use template without type param:
  // inside template scope
  BlobPtr& operator++();
  BlobPtr& operator--();

private:
  std::size_t curr;
};

// return type is not in scope
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
  BlobPtr ret = *this;
  ++(*this);
  return ret;
};

TEST(BlobTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

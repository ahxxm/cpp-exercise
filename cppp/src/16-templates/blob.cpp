#include <utility>
#include "gtest/gtest.h"


template <typename T>
class BlobPtr {
public:
  BlobPtr(): curr(0) { };

  // one exception when use template without type param:
  // inside template scope
  BlobPtr& operator++();
  BlobPtr& operator--();

private:
  std::size_t curr;
  // all instance using same T share this
  static std::size_t count;
};

template<typename T> class ListItem;

// template default arg
template<typename T = int> class List {
public:
  List();
  List(const List&);
  List& operator=(const List&);
  ~List();
  // exercise 11: fix code
  // ListItem is not in this scope, should specify T
  void insert(ListItem<T> *ptr, T value);
private:
  ListItem<T> *front;
};


// return type is not in scope
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
  BlobPtr ret = *this;
  ++(*this);
  return ret;
};


// each instantiantion grants access to
// BlobPtr with same T
template <typename T>
class Blob {
  friend class BlobPtr<T>;
};

template <typename Type>
class Bar {
  // in C++ 11: Type become a friend
  friend Type;

private:
  int i = 0;
};

template<typename T>
using twin = std::pair<T, T>;


TEST(BlobTest, SomeTest) {
  twin<int> b {1, 1};
  EXPECT_EQ(b.first, 1);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include "gtest/gtest.h"
#include <memory>
#include <iostream>


void process(std::shared_ptr<int> p) {
  std::cout << *p << std::endl;
};


// 10: explain the call
// the call construct another shared_ptr using p,
// then pass it to process()
void exercise_ten() {
  std::shared_ptr<int> p(new int(42));
  process(std::shared_ptr<int> (p));
  EXPECT_EQ(*p.get(), 42);
};


// 11: what if call p.get
// "pointer being freed was not allocated"
void exercise_11() {
  std::shared_ptr<int> p(new int(42));
  // process(std::shared_ptr<int> (p.get()));
  EXPECT_EQ(*p.get(), 42);
};


TEST(SmartPointerExerciseTest, SomeTest) {
  exercise_ten();
  exercise_11();
  EXPECT_EQ(1, 1);

  // 13: what happens after delete
  // A: sp gets invalidated!
  // "pointer being freed was not allocated" during end
  // of the program
  auto sp = std::make_shared<int>(2);
  int *p = sp.get();
  // delete p;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

#include <memory>
#include "gtest/gtest.h"


// unique_ptr should be first considered
// almost as fast as raw pointer

class Investment {};

class Stock: public Investment {};
class Bond: public Investment {};
class Cash: public Investment {};


// custom deleter: more efficient
// lambda deleter add less size to smart pointer, than void*
auto delInvmt = [](Investment *pInvestment) {
  // log
  delete pInvestment;
};

// unique_ptr has 2 form:
// - unique_ptr<T>, no [] operator
// - unique_ptr<T[]>, no *deref or -> operator
using return_type = std::unique_ptr<Investment, decltype(delInvmt)>;

template<typename... Ts>
return_type makeInvestment(Ts&&... params) {
  return_type pInv(nullptr, delInvmt);

  //
  // if (stock should be created) {
  pInv.reset(new Stock(std::forward<Ts>(params)...));
  // }
  return pInv;
};


TEST(UniquePtrTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

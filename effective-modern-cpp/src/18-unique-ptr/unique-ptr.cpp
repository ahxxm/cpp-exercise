#include <iostream>
#include <memory>
#include <string>
#include "gtest/gtest.h"


// unique_ptr should be first considered
// almost as fast as raw pointer

class Investment {
public:
  virtual int price() {return 0;};
  virtual ~Investment() {};
};

class Stock: public Investment {
public:
  Stock() = default;
  Stock(const std::string &&) {};
  // FIXME: what if want it to be constexpr
  int price() override final {return 42;};
};
class Bond: public Investment {};
class Cash: public Investment {};


// custom deleter: more efficient
// lambda deleter add less size to smart pointer, than void*
auto delInvmt = [](Investment *pInvestment) {delete pInvestment;};


// unique_ptr has 2 form:
// - unique_ptr<T>, no [] operator
// - unique_ptr<T[]>, no *deref or -> operator
using return_type = std::unique_ptr<Investment, decltype(delInvmt)>;


template<typename... Ts>
return_type makeInvestment(Ts&&... params) {
  return_type pInv(nullptr, delInvmt);

  // if (stock should be created) {
  pInv.reset(new Stock(std::forward<Ts>(params)...));
  // }
  return pInv;
};


TEST(UniquePtrTest, SomeTest) {
  // unique_ptr can be easily converted to shared_ptr
  // std::shared_ptr<Investment> sp = makeInvestment(...  )

  auto aa = makeInvestment(Stock());
  EXPECT_EQ(aa->price(), 42);

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

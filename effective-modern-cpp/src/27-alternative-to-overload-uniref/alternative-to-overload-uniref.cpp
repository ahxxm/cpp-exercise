#include <type_traits>
#include "gtest/gtest.h"


// tag param by std::is_integral and std::true_type


// enable_if<condition>
class Person {
public:

  // when T is not person, nor const/volatile person
  // decay removes these(also turn array into pointer)
  template<typename T, typename = typename std::enable_if<
                         !std::is_same<Person,
                                       typename std::decay<T>::type
                                       >::value
                         >::type>
  explicit Person(T &&) {};

};



TEST(AvoidOverloadUniversalRefTest, SomeTest) {
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

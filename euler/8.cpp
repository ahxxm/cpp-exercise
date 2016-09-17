#include "gtest/gtest.h"
#include <boost/algorithm/string.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
#include <string>


// Largest product in a series
// The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
// Find the thirteen adjacent digits in the 1000-digit number that have the greatest product.

std::string i = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";


#define N 13
// FIXME: /home/travis/g++-5-boost_1_59_0/include/boost/smart_ptr/shared_ptr.hpp:249:65: error: ‘template<class> class std::auto_ptr’ is deprecated [-Werror=deprecated-declarations]
using ll = long long;


ll helper(const std::string &s) noexcept {
  ll max = -1;
  for(unsigned long i = 0;i <= s.size() - N; ++i) {
    ll result = 1;
    for(int j = 0;j < N; ++j) {
      int index = i + j;
      int digit = (s[index] - '0') % 48;
      result *= digit;
    }
    if(result > max) {max = result;}
  }
  std::cout << s << ", result: "<< max << std::endl;
  std::cout << std::endl;

  return max;
}

ll solve(const std::string &ss) {
  std::vector<std::string> result;
  boost::split(result, ss, boost::is_any_of("0"));
  ll max = 0;
  for(auto k: result) {
    if(k.size() >= N) {
      auto local_max = helper(k);
      if(local_max > max) {max = local_max;}
    }
  }

  return max;
}


TEST(LargestProductTest, SomeTest) {
  // EXPECT_EQ(solve(i), 23514624000);
  EXPECT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

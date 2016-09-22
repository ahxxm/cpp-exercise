#include "gtest/gtest.h"
#include <map>
#include <vector>

/*

The following iterative sequence is defined for the set of positive
integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following
sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1


Which starting number, under one million, produces the longest chain?
NOTE: Once the chain starts the terms are allowed to go above one
million.
*/


// initial lize a vector of length N
using ll = long long;
ll N = 1000000;
ll init = 0;

// index->count
using mm = std::map<ll, ll>;
mm length;


ll get_with_default(mm &dict, const ll key) {
  auto it = dict.find(key);
  if(it == dict.end()) {return init;}
  return it->second;
}


ll next(ll num) {
  if(num % 2 == 0) {return num / 2;}
  else {return 3 * num + 1;}
}

ll get_length(ll index) {
  auto n = next(index + 1);
  ll next_length = get_with_default(length, n - 1);

  if(next_length != init) {
    length[index] = next_length + 1;
    return length[index];
  } else {
    // index of next is n-1
    return get_length(n - 1) + 1;
  }
}

ll solve() {
  ll num_of_max_length = 1;
  ll index = 1;
  ll result;
  while(index < N) {
    auto local_length = get_length(index);
    if(local_length > num_of_max_length) {
      num_of_max_length = local_length;
      result = index + 1;
    }
    ++index;
  }
  std::cout << "Number: " << result
            << ", length: " << num_of_max_length << std::endl;

  return result;
}

TEST(LongestCollatzTest, SomeTest) {
  length[0] = 1;
  ll i = 5;
  EXPECT_EQ(get_length(i - 1), 6);
  // std::cout << solve() << std::endl;

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}

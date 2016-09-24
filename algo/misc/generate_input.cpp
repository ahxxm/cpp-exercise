#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

int main(void) {
  // current time as seed
  std::srand(std::time(0));

  std::string filename("input.in");
  std::cout << "Generating random number to: "
            << filename
            << std::endl;

  typedef uint64_t ll;
  ll line_count = 100000;

  std::ofstream out;
  out.open(filename, std::ofstream::out);
  for (ll i = 0; i != line_count; ++i) {
    int rand = std::rand();
    out << rand << "\n";
  };
  out.close();

  return 0;
}

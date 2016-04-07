#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>


// int main(int argc, char *argv[]) {
  // TODO: read int from input
  // if (argc != 3) {
  //   std::cout << "Usage: ./generate_input maximum_number line_count" << std::endl;
  //   return 0;
  // } else {
  //   std::string a = *++argv;
  //   std::string b = *++argv;
  //   std::cout << a << std::endl;
  //   std::cout << b << std::endl;
  // };


int main(void) {
  // current time as seed
  std::srand(std::time(0));

  std::string filename("input.in");
  std::cout << "Generating random number to: "
            << filename
            << std::endl;

  typedef unsigned long long ll;
  ll line_count = 10000000;

  std::ofstream out;
  out.open(filename, std::ofstream::out);
  for (ll i = 0;i != line_count; ++i) {
    int rand = std::rand();
    out << rand << "\n";
  };
  out.close();

  return 0;
}

#include <iostream>
#include <string>
#include <cctype>

void wut(int argc, char *argv[]){
  const std::string hexdigits("0123456789ABCDEF");
  std::string result;
  std::string::size_type n;

  // FIXME: why "12 0 15 8 15" + enter , it does not print anything?
  while (std::cin >> n) {
    if (n < hexdigits.size()) {
      result += hexdigits[n];
    }
  }

  std::cout << result << std::endl;

}

#include <stdexcept>
#include <iostream>

int main(int argc, char *argv[]) {
  // Once caught, other catch won't be executed.
  try {
    // int a = 1;
    throw std::runtime_error("Java");
  } catch (std::runtime_error err) {
    const char *error_message = err.what();
    std::cout << error_message << std::endl;
  }
  // catch (std::logic_error) {
  // std::cout << "should not be this error.. " << std::endl;
  // }
}

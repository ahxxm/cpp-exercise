#include <stdexcept>
#include <iostream>

void first_exception() {
  try {
    // int a = 1;
    throw std::runtime_error("Java");
  } catch (std::runtime_error) {
    std::cout << "java caught..."  << std::endl;
  } catch (std::logic_error) {
    std::cout << "should not be this error.. " << std::endl;
  }
}

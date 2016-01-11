#include <iostream>
#include <string>

// 25: main that takes 2 argument, concatenate the supplied arguments and print result string
// int main(int argc, char *argv[]) {
int main_printer(int argc, char *argv[]) {
  // argv[0] could be "./a.out"
  if (argc != 3) {
    std::cout << "Input should be exactly 2 arguments." << std::endl;
  } else {
    // FIXME: explicitly convert
    std::string i = argv[1];
    std::string j = argv[2];
    std::string concat = i + j;
    std::cout << concat << std::endl;
  }

  return 0;
}


// 26: print values passed to main
int main_print_values(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "No option found." << std::endl;
  } else {
    // cout options(other than ./a.out)
    // FIXME: compute argc?
    int size = argc;
    for (int index = 1; index != size; ++index) {
      std::string option = argv[index];
      std::cout << option << std::endl;
    }
  }

  return 0;
}

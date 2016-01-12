#include <string>

// 36: return a reference to array of 10 strings
std::string (&return_array_of10_string(void))[10];



// 37: use type alias, trailing return, to finish 36
// type alias
typedef std::string sa[10];
using salias = std::string[10];
sa &return_array_of_10_string_alas(void);
salias &alias(void);

// trailing return
// FIXME: how??
// auto return_array_of_10_string_trailing(void) -> decltype(&sa);

#pragma once

// Note: MAX_DISH_NAME_SIZE must be in the header and has constexpr keyword
// because C++ requires array sizes inside structs to be known at compile-time.
constexpr int MAX_DISH_NAME_SIZE = 100;

// We need extern to declare that these variables are defined in another file
// (constants.cpp) Otherwise compiler would complain about multiple definition
// of the same variable.
extern const char FILENAME[];
extern const char TEMP_FILENAME[];
#include <iostream>

#define expect(expression, expected)                                           \
    {                                                                          \
        if (expression != expected) {                                          \
            std::cout << std::boolalpha << "\x1b[1;31mFAIL: " << #expression   \
                      << " == " << expression << " != " << expected << '\n';   \
        } else {                                                               \
            std::cout << std::boolalpha << "\x1b[1;32mPASS: " << #expression   \
                      << " == " << expression << " == " << expected << '\n';   \
        }                                                                      \
    }
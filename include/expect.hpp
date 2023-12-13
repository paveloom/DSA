#include <iostream>

#define expect(expression, expected)                                           \
    {                                                                          \
        if (expression != expected) {                                          \
            std::cout << std::boolalpha << "\x1b[1;31mFAIL: " << #expression   \
                      << " == " << expression << " != " << expected            \
                      << "\x1b[0m\n";                                          \
        } else {                                                               \
            std::cout << std::boolalpha << "\x1b[1;32mPASS: " << #expression   \
                      << " == " << expression << " == " << expected            \
                      << "\x1b[0m\n";                                          \
        }                                                                      \
    }
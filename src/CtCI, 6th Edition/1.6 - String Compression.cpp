#include "expect.hpp"
#include "registry.hpp"

#include <string>

// 1.6 - String Compression: Implement a method to perform basic string
// compression using the counts of repeated characters. For example, the string
// `aabcccccaaa` would become `a2b1c5a3`. If the "compressed" string would not
// become smaller than the original string, your method should return the
// original string. You can assume the string has only uppercase and lowercase
// letters (a - z).

namespace {
class Solution {
    // Time complexity: O(n)
    // Space complexity: O(n)
    static std::string solve(std::string original) {
        size_t n = original.length();
        std::string compressed;
        compressed.reserve(n);

        char count = 0;
        for (size_t i = 0; i < n; i++) {
            count++;
            if (i + 1 == n || original[i] != original[i + 1]) {
                compressed += original[i] + std::to_string(count);
                count = 0;
            }
        }

        return compressed.length() < original.length() ? compressed : original;
    }
    static void run() {
        expect(solve("aabcccccaaa"), "a2b1c5a3");
        expect(solve("aabccaaa"), "aabccaaa");
    }
public:
    Solution() {
        Registry::reg("string-compression", &Solution::run);
    }
};
}

const Solution solution = Solution();
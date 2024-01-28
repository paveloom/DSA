#include "expect.hpp"
#include "registry.hpp"

#include <string>

// 1.5 - One Away: There are three types of edits that can be performed on
// strings: insert a character, remove a character, or replace a character.
// Given two strings, write a function to check if they are one edit (or zero
// edits) away.
//
// EXAMPLE
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bae -> false

namespace {
class Solution {
    // Time complexity: O(n), where `n` is the length of the shortest string
    // Space complexity: O(1)
    static bool solve(const std::string& s1, const std::string& s2) {
        const auto s1_length = static_cast<ssize_t>(s1.length());
        const auto s2_length = static_cast<ssize_t>(s2.length());
        const ssize_t length_difference = std::abs(s1_length - s2_length);

        if (length_difference > 1) {
            return false;
        }

        auto s_bigger = (s1_length > s2_length) ? s1 : s2;
        auto s_smaller = (s1_length > s2_length) ? s2 : s1;

        bool change_found = false;
        for (size_t i_s = 0, i_b = 0;
             i_s < s_smaller.length() && i_b < s_bigger.length();
             i_s++, i_b++) {
            if (s_bigger[i_b] != s_smaller[i_s]) {
                if (change_found) {
                    return false;
                }
                change_found = true;
                if (length_difference == 1) {
                    i_s--;
                }
            }
        }
        return true;
    }
    static void run() {
        expect(solve("pale", "ple"), true);
        expect(solve("pales", "pale"), true);
        expect(solve("pale", "bale"), true);
        expect(solve("pale", "bae"), false);
        expect(solve("pale", "pale"), true);
    }
public:
    Solution() {
        Registry::reg("one-away", &Solution::run);
    }
};
}

const Solution solution = Solution();

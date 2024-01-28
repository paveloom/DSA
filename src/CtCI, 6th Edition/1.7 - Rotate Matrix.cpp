#include "expect.hpp"
#include "registry.hpp"

#include <array>
#include <numeric>
#include <span>

// 1.7 - Rotate Matrix: Given an image represented by an NxN matrix, where each
// pixel in the image is 4 bytes, write a method to rotate the image by 90
// degrees. Can you do this in place?

namespace {
class Solution {
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    static void solve(std::span<int> matrix, int n) {
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                const int tl_index = i * n + j;
                const int tr_index = i * n + (n - 1 - j);
                const int br_index = (n - 1 - i) * n + (n - 1 - j);
                const int bl_index = (n - 1 - i) * n + j;
                const int tl = matrix[tl_index];
                const int tr = matrix[tr_index];
                const int br = matrix[br_index];
                const int bl = matrix[bl_index];
                matrix[tl_index] = bl;
                matrix[tr_index] = tl;
                matrix[br_index] = tr;
                matrix[bl_index] = br;
            }
        }
    }
    static void run() {
        std::array<int, 9> matrix = {};
        std::iota(matrix.begin(), matrix.end(), 1);
        solve(matrix, 3);

        for (auto x : matrix) {
            std::cout << x << '\n';
        }
        // expect(, "aabccaaa");
    }
public:
    Solution() {
        Registry::reg("rotate-matrix", &Solution::run);
    }
};
}

const Solution solution = Solution();
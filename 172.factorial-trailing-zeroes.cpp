/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0) {
            int tmp = n - 1;
            while (n % 5 == 0) {
                ++ans;
                n /= 5;
            }
            n = tmp;
        }
        return ans;
    }
};
// @lc code=end


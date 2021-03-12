/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int c = (a & b & INT_MAX) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
// @lc code=end


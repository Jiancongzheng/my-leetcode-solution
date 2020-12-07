/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int rest = x % 10;
            if (ans > INT_MAX / 10 or ans < INT_MIN / 10 or (ans == INT_MAX / 10 and rest > 7) or (ans == INT_MIN and rest < -8)) return 0;
            ans = ans * 10 + rest;
            x = x / 10;
        }
        return ans;
    }
};
// @lc code=end


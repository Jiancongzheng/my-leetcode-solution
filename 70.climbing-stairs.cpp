/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int dp1 = 1;
        int dp2 = 2;
        for (int i = 3; i <= n; ++i) {
            int tmp = dp2;
            dp2 = dp1 + dp2;
            dp1 = tmp;
        }
        return dp2;
    }
};
// @lc code=end


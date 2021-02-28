/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp1 = 0;
        int dp2 = 0;
        for (int& n : nums) {
            int tmp = dp2;
            dp2 = n + dp1;
            dp1 = max(tmp, dp1);
        }
        return max(dp1, dp2);
    }
};
// @lc code=end


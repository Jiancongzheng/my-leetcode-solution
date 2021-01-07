/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start

// Time complexity log(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int ans = 1;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start

// Time complexity nlog(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.emplace_back(nums.front());
        for (int& num: nums) {
            int l = 0;
            int r = dp.size() - 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (dp[m] < num) l = m + 1;
                else r = m;
            }
            if (dp[l] < num) {
                dp.emplace_back(num);
            }
            else dp[l] = num;
        }
        return dp.size();
    }
};
// @lc code=end


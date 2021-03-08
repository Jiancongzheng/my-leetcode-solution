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
        if (nums.size() == 1) return 1;
        vector<int> dp{nums.front()};
        for (const int& n : nums) {
            int l = 0;
            int r = dp.size() - 1;
            if (dp.back() < n) {
                dp.emplace_back(n);
                continue;
            }
            while (l < r) {
                int m = l + (r - l) / 2;
                if (dp[m] < n) l = m + 1;
                else r = m;
            }
            dp[l] = n;
        }
        return dp.size();
    }
};
// @lc code=end


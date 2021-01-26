/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int j = 1; j < m; ++j) {
            for (int i = n - 2; i >= 0; --i) {
                dp[i] = dp[i] + dp[i + 1];
            }
        } 
        return dp.front();
    }
};
// @lc code=end


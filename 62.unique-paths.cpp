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
        for (int i = 1; i < m; ++i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[j] = dp[j] + dp[j + 1];
            }
        } 
        return dp.front();
    }
};
// @lc code=end


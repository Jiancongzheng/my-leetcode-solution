/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        vector<int> dp = grid.back();
        dp.emplace_back(INT_MAX);
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = dp[i] + dp[i + 1];
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp.front();
    }
};
// @lc code=end


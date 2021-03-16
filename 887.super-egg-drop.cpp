/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            dp[1][i] = i;
        }

        for (int i = 2; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                int l = 1;
                int h = j;
                while (l < h - 1) {
                    int m = l + (h - l) / 2;
                    if (dp[i - 1][m - 1] < dp[i][j - m]) l = m;
                    else if (dp[i - 1][m - 1] > dp[i][j - m]) h = m;
                    else l = h = m;  
                }

                dp[i][j] = 1 + min(max(dp[i - 1][l - 1], dp[i][j - l]), 
                                   max(dp[i - 1][h - 1], dp[i][h - l]));
            }
        }

        return dp[k][n];
    }
};
// @lc code=end


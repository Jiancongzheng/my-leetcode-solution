/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        if (coins.front() > amount) return -1;
        dp[0] = 0;
        for (int i = coins.front(); i <= amount; ++i) {
            int cnt = INT_MAX;
            for (auto& c : coins) {
                if (i - c < 0) break;
                if (dp[i - c] < 0) continue;
                cnt = min(cnt, dp[i - c] + 1);
            }
            if (cnt != INT_MAX) dp[i] = cnt;
        }
        
        return dp.back();
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start

/**
    str * 1 2
    dp  0 1 
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() or s[0] == '0') return 0;
        int len = s.length();
        vector<int> dp(len + 1, 1);
        for (int i = 2; i < len + 1; ++i) {
            int singleDig = s[i - 1] - '0';
            int doubleDig = singleDig + (s[i - 2] - '0') * 10;
            if (doubleDig == 0 or doubleDig > 26 and singleDig == 0) return 0;
            if (doubleDig > 26 or doubleDig < 10) {
                dp[i] = dp[i - 1];
                continue;
            }
            if (singleDig == 0) {
                dp[i] = dp[i - 2];
                continue;
            }
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[len];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

// Time Limit Exceeded
class Solution1 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.length(); ++i) {
            string tmp = s.substr(0, i);
            if (us.count(tmp) == 0) continue;
            cout << tmp << endl;
            if (i == s.length()) return true;
            tmp = s.substr(i, s.length() - i);
            if (wordBreak(tmp, wordDict)) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp.front() = true;
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        for (int i = 0; i <= s.length(); ++i) {
            if (dp[i] == false) continue;
            for (int j = 1; j <= s.length() - i + 1; ++j) {
                string tmp = s.substr(i, j);
                if (us.count(tmp) != 0) dp[i + j] = true;
            }
        }
        return dp.back();
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
private:
    bool isPalindromic(string s) {
        int len = s.length();
        for (int i = 0, j = len - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int strLen = s.length();
        vector<int> dp(strLen, 1);
        if (strLen == 1) return s;
        string ans;
        ans.push_back(s[0]);
        for (int i = 1; i < strLen; ++i) {
            int start = i - 1 - dp[i - 1];
            if (start >= 0 and s[start] == s[i]) {
                dp[i] = dp[i - 1] + 2;
                if (dp[i] > ans.size()) {
                    ans = s.substr(start, dp[i]);
                }
                continue;
            }
            if (start < 0) start = 0;
            for (;start < i; ++start) {
                string tmpStr = s.substr(start, i - start + 1);
                if (isPalindromic(tmpStr)) {
                    dp[i] = tmpStr.length();
                    if (dp[i] > ans.size()) {
                        ans = s.substr(start, dp[i]);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


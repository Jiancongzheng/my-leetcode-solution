/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if (s.empty()) return ans;
        int len = s.length();
        vector<int> dp = vector<int>(len, 1);
        map<char, int> list;
        list[s[0]] = 0;
        ans = 1;
        for (int i = 1; i < len; ++i) {
            char ch = s[i];
            if (list.find(ch) == list.end()) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = min(i - list[ch], dp[i-1] + 1);
            }
            list[ch] = i;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
// @lc code=end


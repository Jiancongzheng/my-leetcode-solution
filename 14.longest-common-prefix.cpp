/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
private:
    string commonPrefix(string str1, string str2) {
        int len = min(str1.length(), str2.length());
        for (int i = len; i >= 1; --i) {
            if (str1.substr(0, i) == str2.substr(0, i)) return str2.substr(0, i);
        }
        return string();
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return string();
        string ans = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            ans = commonPrefix(ans, strs[i]);
        }
        return ans;
    }
};
// @lc code=end


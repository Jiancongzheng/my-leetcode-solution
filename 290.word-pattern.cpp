/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string str;
        unordered_map<char, string> ch2str;
        unordered_map<string, char> str2ch;
        int idx = 0;
        int cnt = 0;
        for (int i = 0; i <=s.length(); ++i) {
            char c;
            if (i == s.length()) c = ' ';
            else c = s[i];
            if (c == ' ') {
                if (idx >= pattern.size()) return false;
                if (ch2str.find(pattern[idx]) != ch2str.end() and ch2str[pattern[idx]] != str) return false;
                if (str2ch.find(str) != str2ch.end() and str2ch[str] != pattern[idx]) return false;
                ch2str[pattern[idx]] = str;
                str2ch[str] = pattern[idx];
                ++idx;
                ++cnt;
                str = "";
                continue;
            }
            str.push_back(c);
        }
        if (cnt != pattern.size()) return false;
        return true;
    }
};
// @lc code=end


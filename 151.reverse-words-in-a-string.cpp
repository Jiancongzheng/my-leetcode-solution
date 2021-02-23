/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        vector<string> v;
        string tmp = string();
        for (int i = 0; i < len; ++i) {
            if (tmp.empty() and s[i] == ' ') continue;
            if (s[i] == ' ') {
                v.emplace_back(tmp);
                tmp = string(); 
                continue;
            }
            tmp.push_back(s[i]);
        }
        string ans = string();
        if (!tmp.empty()) ans = tmp;
        for (int i = v.size() - 1; i >= 0; --i) {
            string str = v[i];
            if (ans.empty()) ans = str;
            else {
                ans += " " + str;
            }
        }
        return ans;
    }
};
// @lc code=end


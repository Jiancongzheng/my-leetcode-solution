/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
private:
    bool isPalindrome(string& s) {
        for (int l = 0, r = s.length() - 1; l < r; ++l, --r) {
            if (s[l] != s[r]) return false;
        }
        return true;
    }

    void helper(string s, vector<string>& cand, vector<vector<string>>& ans) {
        if (s.empty()) return;
        if (isPalindrome(s)) {
            cand.emplace_back(s);
            ans.emplace_back(cand);
            cand.pop_back();
        }

        for (int i = 1; i <= s.length(); ++i) {
            string pre = s.substr(0, i);
            string post = s.substr(i, s.length() - i);
            if (isPalindrome(pre)) {
                cand.emplace_back(pre);
                helper(post, cand, ans);
                cand.pop_back();
            }
        }

        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> cand;
        vector<vector<string>> ans;
        helper(s, cand, ans);
        return ans;
    }
};
// @lc code=end


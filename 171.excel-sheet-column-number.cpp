/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (char& c : s) {
            ans *= 26;
            int n = c - 'A' + 1;
            ans += n;
        }
        return ans;
    }
};
// @lc code=end


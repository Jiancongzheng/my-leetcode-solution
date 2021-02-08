/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
                ++l;
                continue;
            }

            if (!isalnum(s[r])){
                --r;
                continue;
            }

            if (tolower(s[r]) != tolower(s[l])) return false;
            --r;
            ++l;
        }
        return true;
    }
};
// @lc code=end


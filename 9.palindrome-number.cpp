/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        if (x % 10 == 0) return false;
        int y = 0;
        while (y < x) {
            y = 10 * y + x % 10;
            x = x / 10;
        }
        if (x == y or x == y / 10) return true;
        return false;
    }
};
// @lc code=end


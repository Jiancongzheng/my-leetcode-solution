/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
private:
    unordered_set<int> vowels{
        'a',
        'e',
        'i',
        'o',
        'u',
        'A',
        'E',
        'I',
        'O',
        'U'
    };
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            while (vowels.count(s[l]) == 0 and l < r) ++l;
            while (vowels.count(s[r]) == 0 and r > l) --r;
            if (r == l) break;
            swap(s[l], s[r]);
            ++l;
            --r;
        }
        return s;
    }
};
// @lc code=end


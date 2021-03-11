/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        vector<int> pos;
        for (int i = 0; i < s.length(); ++i) {
            const char ch = tolower(s[i]);
            if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') {
                pos.emplace_back(i);
            }
        }

        for (int i = 0, j = pos.size() - 1; i < j; ++i, --j) {
            int l = pos[i];
            int r = pos[j];
            swap(s[l], s[r]);
        }

        return s;
    }
};
// @lc code=end


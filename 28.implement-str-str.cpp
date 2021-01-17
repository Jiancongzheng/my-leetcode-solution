/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenH = haystack.size();
        int lenN = needle.size();
        for (int i = 0; i <= lenH - lenN; ++i) {
            bool returnFlag = true;
            for (int j = 0; j < lenN; ++j) {
                if (needle[j] != haystack[i + j]) {
                    returnFlag = false;
                    break;
                }
            }
            if (returnFlag) return i;
        }
        return -1;
    }
};
// @lc code=end


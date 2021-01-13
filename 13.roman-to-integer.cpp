/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        bool VX = false;
        bool LC = false;
        bool DM = false;
        for (int i = s.length() - 1; i >= 0; --i) {
            const char& ch = s[i];
            switch (ch) {
                case 'I':
                    if (VX) ans -= 1;
                    else ans += 1;
                    break;
                case 'V':
                    ans += 5;
                    VX = true;
                    break;
                case 'X':
                    if (LC) ans -= 10;
                    else ans += 10;
                    VX = true;
                    break;
                case 'L':
                    ans += 50;
                    LC = true;
                    break;
                case 'C':
                    if (DM) ans -= 100;
                    else ans += 100;
                    LC = true;
                    break;
                case 'D':
                    ans += 500;
                    DM = true;
                    break;
                case 'M':
                    ans += 1000;
                    DM = true;
                    break;
                default:
                    return -1;
            }
        }
        return ans;
    }
};
// @lc code=end


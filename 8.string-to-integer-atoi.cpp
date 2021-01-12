/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1;
        int start_pos = 0;
        while (s[start_pos] == ' ') ++start_pos;
        if (s[start_pos] == '-') {
            sign = -1;
            ++start_pos;
        }
        else if (s[start_pos] == '+') {
            ++start_pos;
        }
        else if (s[start_pos] < '0' or s[start_pos] > '9') return ans;

        for (int i = start_pos; i < s.length(); ++i) {
            if (s[i] < '0' or s[i] > '9') break;
            int dig = s[i] - '0';
            if (ans > 0 and ans > (INT_MAX - dig) / 10) return INT_MAX;
            if (ans < 0 and ans < (INT_MIN + dig) / 10) return INT_MIN;
            ans = 10 * ans + sign * dig;
        }
        return ans;
    }
};
// @lc code=end


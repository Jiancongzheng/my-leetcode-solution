/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        vector<int> digits(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int idx1 = i + j;
                int idx2 = idx1 + 1;
                int sum = mul + digits[idx2];
                digits[idx1] += sum / 10;
                digits[idx2] = sum % 10;
            }
        }
        string res;
        for (int i = 0; i < m + n; ++i) {
            if (!res.empty() or digits[i] != 0) {
                res.push_back('0' + digits[i]);
            }
        }
        if (res.empty()) return "0";
        return res;
    }
};
// @lc code=end


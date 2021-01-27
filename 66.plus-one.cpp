/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int sum = c + digits[i];
            c = sum / 10;
            ans.emplace_back(sum % 10);
        }
        if (c == 1) ans.emplace_back(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int& n : nums) {
            res ^= n;
        }

        for (int i = 0; i <= nums.size(); ++i) {
            res ^= i;
        }

        return res;
    }
};
// @lc code=end


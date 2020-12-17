/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int last = ans;
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            last = max(num, num + last);
            ans = max(ans, last);
        }
        return ans;
    }
};
// @lc code=end


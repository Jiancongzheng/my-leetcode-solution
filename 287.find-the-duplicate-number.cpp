/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int& n : nums) {
            while (nums[n - 1] != n) swap(n, nums[n - 1]);
        }
        return nums.back();
    }
};
// @lc code=end


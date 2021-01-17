/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = nums.size() - 2;
        while (left >= 0 and nums[left] >= nums[left + 1]) --left;
        if (left >= 0) {
            int right = nums.size() - 1;
            while (right >= left and nums[right] <= nums[left]) --right;
            swap(nums[right], nums[left]);
        }
        reverse(nums.begin() + left + 1, nums.end());
        return;
    }
};
// @lc code=end


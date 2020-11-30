/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len - 1;
        for (; i >= 0; --i) {
            if (i == 0) break;
            if (nums[i - 1] < nums[i]) break; 
        }

        if (i == 0) {
            for (; i < len / 2; ++i) {
                swap(nums[i], nums[len - i - 1]);
            }
            return;
        }

        int j = len - 1;
        for (; j >= i; --j) {
            if (nums[j] > nums[i - 1]) {
                swap(nums[j], nums[i - 1]);
                break;
            }
        }

        sort(nums.begin() + i, nums.end());
    }
};
// @lc code=end


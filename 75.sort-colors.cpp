/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        for (int i = 0; i <= r; ++i) {
            while (l < nums.size() and nums[l] == 0) ++l;
            while (r >= 0 and nums[r] == 2) --r;
            if (r <= l) return;
            if (nums[i] == 0 and i > l) {
                swap(nums[i], nums[l]);
                ++l;
                --i;
                continue;
            }
            if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                --r;
                --i;
                continue;
            }
        }
        return;
    }
};
// @lc code=end


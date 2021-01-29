/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return;
        int l = 0;
        int r = len - 1;
        for (int i = 0; i <= r; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
                i--;
            }
        }
        return;
    }
};
// @lc code=end


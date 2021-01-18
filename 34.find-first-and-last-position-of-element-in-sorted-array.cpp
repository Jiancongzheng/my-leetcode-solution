/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int l = 0;
        vector<int> res{-1, -1};
        if (r < 0) return res; 
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        if (nums[l] != target) return res;
        res[0] = l;
        r = nums.size() - 1;
        l = 0;
        while (l < r) {
            int m = (l + r) / 2 + (l + r) % 2;
            if (nums[m] <= target) l = m;
            else r = m - 1;
        }
        res[1] = r;
        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;

            const int& numM = nums[m];
            const int& numL = nums[l];
            const int& numR = nums[r];

            if (numM == target) return m;
            if (numL == target) return l;
            if (numR == target) return r;

            if (numM > target) {
                if (numM > numL and numL > target) {
                    l = m + 1;
                    continue;
                }
                r = m;
            }
            else {
                if (numM < numR and target > numR) {
                    r = m;
                    continue;
                }
                l = m + 1;
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};
// @lc code=end


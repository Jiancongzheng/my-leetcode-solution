/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = nums.size() - 1;
        if (pos == -1) return 0;
        for (int i = 0; i <= pos; ++i) {
            while (nums[i] == val and i <= pos) {
                swap(nums[i], nums[pos]);
                --pos;
            }
        }
        return pos + 1;
    }
};
// @lc code=end


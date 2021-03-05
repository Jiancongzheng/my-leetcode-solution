/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNoneZero = 0;
        for (int& n : nums) {
            if (n != 0) {
                swap(n, nums[lastNoneZero]);
                ++lastNoneZero;
            }
        }
    }
};
// @lc code=end


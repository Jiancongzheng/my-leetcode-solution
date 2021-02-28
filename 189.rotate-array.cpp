/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto tmp = nums;
        k = k % nums.size();
        k = nums.size() - k;                                                                                           
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = tmp[(i + k) % nums.size()];
        }
    }
};
// @lc code=end


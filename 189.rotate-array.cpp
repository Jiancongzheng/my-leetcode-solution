/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        while (k > 0) {
            nums.insert(nums.begin(), nums.back());
            nums.erase(nums.end() - 1);
            --k;
        }
    }
};
// @lc code=end


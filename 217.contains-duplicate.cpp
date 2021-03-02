/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        return us.size() < nums.size();
    }
};
// @lc code=end


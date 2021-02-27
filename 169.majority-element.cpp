/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums.front();
        int cnt = 0;
        for (int& n: nums) {
            if (n == ans) ++cnt;
            else --cnt;
            if (cnt < 0) {
                cnt = 1;
                ans = n;
            }
        }
        return ans;
    }
};
// @lc code=end


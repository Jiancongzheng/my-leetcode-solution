/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue pq(nums.begin(), nums.end());
        for (int i = 1; i < k; ++i) pq.pop();
        return pq.top();
    }
};
// @lc code=end


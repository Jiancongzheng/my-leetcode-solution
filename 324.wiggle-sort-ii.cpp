/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        stack<int> odd;
        stack<int> eve;
        for (int i = 0; i < len / 2 + len % 2; ++i) {
            eve.push(nums[i]);
        }
        for (int i = len / 2 + len % 2; i < len; ++i) {
            odd.push(nums[i]);
        }

        for (int i = 0; i < len; ++i) {
            if (i % 2 == 1) {
                nums[i] = odd.top();
                odd.pop();
            }
            else {
                nums[i] = eve.top();
                eve.pop();
            }
        }
    }
};
// @lc code=end


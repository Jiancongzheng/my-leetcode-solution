/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> list;
        vector<int> ans;
        for (int idx = 0; idx < nums.size(); ++idx) {
            int num = nums[idx];
            if (list.find(target - num) == list.end()) {
                list[num] = idx;
                continue;
            }
            ans = vector<int>{list[target - num], idx};
            break;
        }
        return ans;
    }
};
// @lc code=end


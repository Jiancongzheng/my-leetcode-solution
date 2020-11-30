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
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (list.find(target - num) == list.end()) {
                list[num] = i;
                continue;
            }
            res = vector<int>{list[target - num], i};
            break;
        }
        return res;
    }
};
// @lc code=end


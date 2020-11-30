/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> list;
        std::vector<int> ans;
        for (int idx = 0; idx < nums.size(); ++idx) {
            int num = nums[idx];
            if (list.find(target - num) == list.end()) {
                list[num] = idx;
                continue;
            }
            ans = std::vector<int>{list[target - num], idx};
            break;
        }
        return ans;
    }
};
// @lc code=end


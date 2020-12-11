/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
private:
    void twoSum(vector<int>& nums, int idx, int target, vector<vector<int>>& ans) {
        map<int, int> m;
        for (int i = idx + 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (m.find(target - num) != m.end()) {
                ans.emplace_back(vector<int>{nums[idx], target - num, num});
                while (i < nums.size() and nums[i] == num) {
                    ++i;
                }
                --i;
            }
            else m[num] = i;


        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size();) {
            int num = nums[i];
            if (num > 0) break;
            twoSum(nums, i, 0 - num, ans);
            while (i < nums.size() and nums[i] == num) {
                ++i;
            }
        }
        return ans;
    }
};
// @lc code=end


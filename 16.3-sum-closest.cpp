/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
private:
    void dfs(int&& pos, const vector<int>& nums, const int& target, vector<int>& sum_list, int& ans) {
        if (sum_list.size() == 3) {
            int sum3 = sum_list[0] + sum_list[1] + sum_list[2];
            if (abs(sum3 - target) < abs(ans - target)) ans = sum3;
            return;
        }

        for (int i = pos; i < nums.size(); ++i) {
            sum_list.emplace_back(nums[i]);
            dfs(i + 1, nums, target, sum_list, ans);
            sum_list.pop_back();
        }
        return;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        vector<int> sum_list;
        dfs(0, nums, target, sum_list, ans);
        return ans;
    }
};
// @lc code=end


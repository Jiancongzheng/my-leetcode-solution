/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        if (len == 3) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; ++i) {
            int r = len - 1;
            int l = i + 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;
                
                if (abs(ans - target) > abs(sum - target)) ans = sum;

                if (sum < target) ++l;
                else --r;
            }
        }
        return ans;
    }
};
// @lc code=end


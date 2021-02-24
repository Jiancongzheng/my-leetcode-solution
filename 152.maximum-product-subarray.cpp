/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums.front();
        if (nums.size() == 1) return ans;
        int minP = 0, maxP = 0;
        for (int& n: nums) {
            int tmpMax = max(maxP * n, minP * n);
            int tmpMin = min(minP * n, maxP * n);
            maxP = max(n, tmpMax);
            minP = min(tmpMin, n);
            ans = max(ans, maxP);
        }
        return ans;
    }
};
// @lc code=end


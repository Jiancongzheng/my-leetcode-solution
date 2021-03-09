/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp;
        dp.emplace_back(nums.front());
        for (const int& n : nums) {
            if (n > dp.back()) {
                dp.emplace_back(n);
                if (dp.size() == 3) return true;
                continue;
            }
            for (int& d : dp) {
                if (d >= n) {
                    d = n;
                    break;
                }
            }
        }
        return false;
    }
};
// @lc code=end


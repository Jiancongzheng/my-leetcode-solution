/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start

// Dynamic programming O(n^2)
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool> dp(len, false);
        dp.back() = true;
        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 1; j < len and j <= i + nums[i]; ++j) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                } 
            }
        }
        return dp.front();
    }
};

// Greedy O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i + nums[i] >= pos) pos = i;
        }
        return pos == 0;
    }
};
// @lc code=end


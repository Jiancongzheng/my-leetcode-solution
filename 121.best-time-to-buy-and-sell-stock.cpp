/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minPriceSoFar = INT_MAX;
        for (int curr = 0; curr < prices.size(); ++curr) {
            int currPrice = prices[curr];
            minPriceSoFar = min(currPrice, minPriceSoFar);
            ans = max(ans, currPrice - minPriceSoFar);
        }
        return ans;
    }
};
// @lc code=end


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
            int price = prices[curr];
            minPriceSoFar = min(price, minPriceSoFar);
            ans = max(ans, price - minPriceSoFar);
        }
        return ans;
    }
};
// @lc code=end


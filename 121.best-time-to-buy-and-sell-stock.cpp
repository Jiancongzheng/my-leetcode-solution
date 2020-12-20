/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int sell = 0, buy = 0;
        for (int curr = 0; curr < prices.size(); ++curr) {
            if (prices[curr] < prices[buy]) {
                maxP = max(maxP, prices[sell] - prices[buy]);
                buy = curr;
                sell = curr;
            }
            
            if (prices[curr] > prices[sell]) {
                sell = curr;
                maxP = max(maxP, prices[sell] - prices[buy]);
            }
        }
        return maxP;
    }
};
// @lc code=end


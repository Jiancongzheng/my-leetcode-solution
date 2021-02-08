/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices.front();
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[i - 1]) {
                profit += prices[i - 1] - buy;
                buy = prices[i];
            }
        }
        return profit + prices.back() - buy;
    }
};
// @lc code=end


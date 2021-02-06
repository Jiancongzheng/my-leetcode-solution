/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int h = prices.front();
        int l = h;
        int res = 0;
        for (int p: prices) {
            if (p > h) {
                h = p;
            }
            if (p < l) {
                if (h - l > res) res = h - l;
                l = p;
                h = p;
            }
        }
        return max(res, h - l);
    }
};
// @lc code=end


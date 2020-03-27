class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) return 0;
        int max = 0;
        int buy = prices[0];
        for (int i = 1; i < len; i++) {
            if (prices[i] < buy) buy = prices[i];
            else if (prices[i] - buy > max) max = prices[i] - buy;
        }
        return max;
    }
};
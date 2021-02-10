/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int sum = 0;
        int tank = 0;
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            tank += gas[i] - cost[i];
            sum  += gas[i] - cost[i];
            if (sum < 0) {
                ans = i + 1;
                sum = 0;
            }
        }
        if (tank >= 0) return ans;
        return -1;
    }
};
// @lc code=end


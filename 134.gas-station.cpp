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
        for (int i = 0; i < len; ++i) {
            if (gas[i] < cost[i]) continue;
            int car = 0;
            for (int j = 0; j < len; ++j) {
                int curr = (i + j) % len;
                car = car + gas[curr] - cost[curr];
                if (car < 0) break;
                int next = (i + j + 1) % len;
                if (next == i) return i;
            }
        }
        return -1;
    }
};
// @lc code=end


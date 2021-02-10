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
        for (int i = 0; i < len;) {
            int car = 0;
            int cnt = 0;
            while (cnt < len) {
                int curr = (i + cnt) % len;
                car += gas[curr] - cost[curr];
                if (car < 0) break;
                ++cnt;
            }
            if (cnt == len) return i;
            i = i + cnt + 1;
        }
        return -1;
    }
};
// @lc code=end


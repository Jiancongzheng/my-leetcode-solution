/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inflow(numCourses, 0);
        vector<vector<int>> courseGraph(numCourses, vector<int>());
        for (auto& pre : prerequisites) {
            ++inflow[pre[0]];
            courseGraph[pre[1]].emplace_back(pre[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inflow[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto& next : courseGraph[curr]) {
                inflow[next] -= 1;
                if (inflow[next] == 0) q.push(next);
            }
        }

        for (int i = 0; i < numCourses; ++i) {
            if (inflow[i] > 0) return false;
        }
        return true;
    }
};
// @lc code=end


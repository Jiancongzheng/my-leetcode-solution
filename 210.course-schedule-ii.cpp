/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> courseQueue;
        vector<vector<int>> courseGraph(numCourses, vector<int>());
        vector<int> inflows(numCourses, 0);
        vector<int> res;
        for (auto& p : prerequisites) {
            ++inflows[p.front()];
            courseGraph[p.back()].emplace_back(p.front());
        }

        for (int i = 0; i < numCourses; ++i) {
            int inflow = inflows[i];
            if (inflow == 0) {
                res.emplace_back(i);
                courseQueue.push(i);
            } 
        }

        while (!courseQueue.empty()) {
            int curr = courseQueue.front();
            courseQueue.pop();
            for (auto& next : courseGraph[curr]) {
                --inflows[next];
                if (inflows[next] == 0) {
                    res.emplace_back(next);
                    courseQueue.push(next);
                }
            }
        }
        if (res.size() == numCourses) return res;
        return vector<int>();
    }
};
// @lc code=end


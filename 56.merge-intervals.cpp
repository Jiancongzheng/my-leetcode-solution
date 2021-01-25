/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        auto curr = intervals.front();
        for (auto& next: intervals) {
            if (curr.back() >= next.front()) {
                curr.back() = max(curr.back(), next.back());
            }
            else {
                ans.emplace_back(curr);
                curr = next;
            }
        }
        ans.emplace_back(curr);
        return ans;
    }
};
// @lc code=end


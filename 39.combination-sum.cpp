/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

// Tips: 用引用的效率要比值传递高得多。
class Solution {
private:
    void dfs(int target, vector<int>& candidates, int idx, vector<vector<int>>& ans, vector<int>& comb) {
        if (target == 0) {
            ans.emplace_back(comb);
            return;
        }
        if (target < 0) {
            return;
        }
        int len = candidates.size();
        for (int i = idx; i < len; ++i) {
            if (candidates[i] > target) break;
            comb.emplace_back(candidates[i]);
            dfs(target - candidates[i], candidates, i, ans, comb);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        dfs(target, candidates, 0, ans, comb);
        return ans;
    }
};
// @lc code=end


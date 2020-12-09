/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
private:
    void dfs(vector<int>& candidates, int target, int idx, 
             vector<int>& combination, 
             vector<vector<int>>& ans) {
        if (target == 0) {
            ans.emplace_back(combination);
            return;
        }
        else if (target < 0) return;

        for (int i = idx; i < candidates.size();) {
            int candidate = candidates[i];
            combination.emplace_back(candidate);
            dfs(candidates, target - candidate, i + 1, combination, ans);
            combination.pop_back();
            while (i < candidates.size() and candidates[i] == candidate) {
                ++i;
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        dfs(candidates, target, 0, combination, ans);
        return ans;
    }
};
// @lc code=end


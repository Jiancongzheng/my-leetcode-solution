/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
private:
    void helper(vector<vector<int>>& res, vector<int> comb, vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            res.emplace_back(comb);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            int num = candidates[i];
            if (num > target) break;
            comb.emplace_back(num);
            helper(res, comb, candidates, target - num, i + 1);
            comb.pop_back();
            while (i < candidates.size() - 1 and candidates[i + 1] == num) ++i;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>      res;
        sort(candidates.begin(), candidates.end());
        helper(res, vector<int>{}, candidates, target, 0);
        return res;
    }
};
// @lc code=end


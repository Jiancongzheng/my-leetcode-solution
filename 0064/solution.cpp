class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> list;
        vector<vector<int>> lists;
        int start = 0;
        dfs(candidates, target, start, list, lists);
        return lists;
    }
    
    void dfs(vector<int>& candidates, int target, int start, vector<int>& list, vector<vector<int>>& lists) {
        if (target == 0) {
            lists.push_back(list);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            list.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, list, lists);
            list.pop_back();
        }
    }
};
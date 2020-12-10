/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private:
    void dfs(vector<vector<int>>& ans, vector<int>& permutation, 
             vector<bool>& visited, vector<int>& nums) {
        if (permutation.size() == nums.size()) {
            ans.emplace_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            int num = nums[i];
            visited[i] = true;
            permutation.emplace_back(num);
            dfs(ans, permutation, visited, nums);
            permutation.pop_back();
            visited[i] = false;
            
            while (i < nums.size() and nums[i] == num) {
                ++i;
            }
            --i;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> permutation;
        vector<bool> visited(nums.size(), false);
        dfs(ans, permutation, visited, nums);
        return ans;
    }
};
// @lc code=end


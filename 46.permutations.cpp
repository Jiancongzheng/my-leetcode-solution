/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
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
            visited[i] = true;
            permutation.push_back(nums[i]);
            dfs(ans, permutation, visited, nums);
            permutation.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permutation;
        vector<bool> visited(nums.size(), false);
        dfs(ans, permutation, visited, nums);
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans{{}};
        for (int num : nums) {
            for (int i = ans.size(); i > 0; --i) {
                vector<int> vec = ans.front();
                ans.erase(ans.begin());
                for (int pos = 0; pos <= vec.size(); ++pos) {
                    vector<int> copy = vec;
                    copy.insert(copy.begin() + pos, num);
                    ans.emplace_back(copy);
                }
            }
        }
        return ans;
    }
};
// @lc code=end


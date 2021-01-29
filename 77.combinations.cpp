/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
private:
    void helper(const int& n, const int& k, const int curr, vector<vector<int>>& ans, vector<int>& com) {
        if (com.size() == k) {
            ans.emplace_back(com);
            return;
        }
        if (com.size() + (n - curr + 1) < k) return;
        for (int i = curr; i <= n; ++i) {
            com.emplace_back(i);
            helper (n, k, i + 1, ans, com);
            com.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> com;
        helper(n, k, 1, ans, com);
        return ans;
    }
};
// @lc code=end


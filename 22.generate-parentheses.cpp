/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void dfs(int numL, int numR, vector<string>& ans, string cand) {
        if (numL > numR) return;
        if (numL < 0) return;
        if (numR == 0 and numL == 0) {
            ans.emplace_back(cand);
            return;
        }
        cand.push_back('(');
        dfs(numL - 1, numR, ans, cand);
        cand.pop_back();
        cand.push_back(')');
        dfs(numL, numR - 1, ans, cand);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, n, ans, string());
        return ans;
    }
};
// @lc code=end


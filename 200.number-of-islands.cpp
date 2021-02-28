/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    void helper(vector<vector<bool>>& v, int i, int j, vector<vector<char>>& grid) {
        if (i < 0 or j < 0 or i >= grid.size() or j >= grid.front().size()) return;
        if (grid[i][j] == '0' or v[i][j] == true) return;
        v[i][j] = true;
        for (auto& d : directions) {
            helper(v, i + d[0], j + d[1], grid);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        vector<vector<bool>> v(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j] == true or grid[i][j] == '0') continue;
                ++ans;
                helper(v, i, j, grid);
            }
        }
        return ans;
    }
};
// @lc code=end


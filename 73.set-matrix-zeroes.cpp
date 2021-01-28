/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();
        vector<vector<int>> l;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    l.emplace_back(vector<int>{i, j});
                }
            }
        }

        for (auto& co: l) {
            for (int row = 0; row < n; ++row) {
                matrix[co[0]][row] = 0;
            }

            for (int col = 0; col < m; ++col) {
                matrix[col][co[1]] = 0;
            }
        }
    }
};
// @lc code=end


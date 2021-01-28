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
        map<int, int> cols;
        map<int, int> rows;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    cols[i] = 1;
                    rows[j] = 1;
                }
            }
        }

        for (auto& col: cols) {
            for (int row = 0; row < n; ++row) {
                matrix[col.first][row] = 0;
            }
        }
        
        for (auto& row: rows) {
            for (int col = 0; col < m; ++col) {
                matrix[col][row.first] = 0;
            }
        }
    }
};
// @lc code=end


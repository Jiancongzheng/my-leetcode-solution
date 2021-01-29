/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();
        int l = 0;
        int r = m * n - 1;
        while (l < r) {
            int c = (l + r) / 2;
            int col = c / n;
            int row = c % n;
            if (matrix[col][row] < target) l = c + 1;
            else r = c;
        }
        return matrix[l / n][l % n] == target;
    }
};
// @lc code=end


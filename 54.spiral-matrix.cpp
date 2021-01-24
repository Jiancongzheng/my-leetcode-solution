/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int bottom = matrix.size() - 1;
        int right = matrix.front().size() - 1;
        int left = 0;
        int top = 0;
        vector<int> ans;
        while (top <= bottom and left <= right) {
            for (int row = left; row <= right; ++row) {
                ans.emplace_back(matrix[top][row]);
            }
            for (int col = top + 1; col <= bottom; ++col) {
                ans.emplace_back(matrix[col][right]);
            }
            if (top != bottom) {
                for (int row = right - 1; row > left; --row) {
                    ans.emplace_back(matrix[bottom][row]);
                }
            }
            if (right != left) {
                for (int col = bottom; col > top; --col) {
                    ans.emplace_back(matrix[col][left]);
                }
            }
            
            --bottom;
            --right;
            ++left;
            ++top;
        }
        return ans;
    }
};
// @lc code=end


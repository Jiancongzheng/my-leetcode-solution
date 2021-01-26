/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;
        while (top <= bottom and left <= right) {
            for (int row = left; row <= right; ++row) {
                ans[top][row] = num;
                ++num;
            }

            for (int col = top + 1; col <= bottom; ++col) {
                ans[col][right] = num;
                ++num;
            }

            if (top != bottom and right != left) {
                for (int row = right - 1; row > left; --row) {
                    ans[bottom][row] = num;
                    ++num;
                }

                for (int col = bottom; col > top; --col) {
                    ans[col][left] = num;
                    ++num;
                }
            }

            ++top;
            --bottom;
            --right;
            ++left;
        }
        return ans;
    }
};
// @lc code=end


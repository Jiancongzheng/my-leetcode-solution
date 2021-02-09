/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> dir{
        {1  ,  0},
        {-1 ,  0},
        {0  ,  1},
        {0  , -1}
    };
    void helper(vector<vector<char>>& board, int col, int row) {
        if (col < 0 or col >= board.size() or row >= board.front().size() or row < 0) return;
        if (board[col][row] != 'O') return;
        board[col][row] = 'i';
        for (auto d: dir) {
            helper(board, col + d[0], row + d[1]);
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m <= 1) return;
        int n = board.front().size();
        if (n <= 1) return;

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') helper(board, i, 0);
            if (board[i][n - 1] == 'O') helper(board, i, n - 1);
        }

        for (int i = 1; i < n - 1; ++i) {
            if (board[0][i] == 'O') helper(board, 0, i);
            if (board[m - 1][i] == 'O') helper(board, m - 1, i);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char& ch = board[i][j];
                if (ch == 'i') ch = 'O';
                else ch = 'X';
            }
        }
    }
};
// @lc code=end


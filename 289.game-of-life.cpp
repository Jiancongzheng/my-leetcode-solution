/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> directions{
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1},
    };

    int countNeighbors(vector<vector<int>>& board, int col, int row) {
        int m = board.size();
        int n = board.front().size();
        int cnt = 0;
        for (auto& d : directions) {
            int nextCol = col + d[0];
            int nextRow = row + d[1];
            if (nextCol < 0 or nextCol >= m or nextRow < 0 or nextRow >= n) continue;
            if (board[nextCol][nextRow] == 1 or board[nextCol][nextRow] == -1) ++cnt;
        }
        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.front().size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = countNeighbors(board, i, j);
                if (board[i][j] == 1) {
                    if (cnt == 2 or cnt == 3) continue;
                    board[i][j] = -1;
                }
                else if (cnt == 3){
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -1) board[i][j] = 0;
                if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};
// @lc code=end


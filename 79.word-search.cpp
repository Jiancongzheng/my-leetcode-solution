/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
    bool helper(vector<vector<char>>& board, const string& word, int&& i, int col, int row) {
        if (col < 0 or row < 0 or col >= board.size() or row >= board.front().size()) return false;
        if (board[col][row] != word[i]) return false;
        if (i == word.size() - 1) return true;
        char ch = board[col][row];
        board[col][row] = '#';
        bool res = helper(board, word, i + 1, col + 1, row) or
                   helper(board, word, i + 1, col - 1, row) or 
                   helper(board, word, i + 1, col, row + 1) or
                   helper(board, word, i + 1, col, row - 1);
        board[col][row] = ch;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.front().size(); ++j) {
                if (board[i][j] == word[0] and helper(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end


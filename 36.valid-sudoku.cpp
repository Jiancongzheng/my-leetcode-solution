/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> init(9, 1);
        for (int i = 0; i < 9; ++i) {
            auto rowChecker = init;
            auto colChecker = init;
            auto bloChecker = init;
            for (int j = 0; j < 9; ++j) {
                const char& chRow = board[i][j];
                const char& chCol = board[j][i];
                const char& chBlo = board[3 * (int)(i / 3) + j / 3][3 * (i % 3) + j % 3];
                
                if (chRow != '.') {
                    int& numRow = rowChecker[chRow - '0' - 1];
                    if (numRow == 0) return false;
                    --numRow;
                }
                if (chCol != '.') {
                    int& numCol = colChecker[chCol - '0' - 1];
                    if (numCol == 0) return false;
                    --numCol;
                }
                if (chBlo != '.') {
                    int& numBlo = bloChecker[chBlo - '0' - 1];
                    if (numBlo == 0) return false;
                    --numBlo;
                }
            }
        }
        return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> container(numRows, "");
        int row = 0;
        bool down = true;
        for (char c: s) {
            container[row].push_back(c);
            if (down) ++row;
            else --row;
            if (row == numRows) {
                down = false;
                row -= 2;
                continue;
            }
            if (row == -1) {
                down = true;
                row += 2;
            }
        }
        string ans;
        for (auto s: container) {
            ans += s;
        }
        return ans;
    }
};
// @lc code=end


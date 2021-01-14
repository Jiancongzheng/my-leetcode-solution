/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
private:
    map<char, int> toNum{
        {'(',  1},
        {')', -1},
        {'{',  2},
        {'}', -2},
        {'[',  3},
        {']', -3}
    };
public:
    bool isValid(string s) {
        stack<int> check;
        for (char& ch: s) {
            int num = toNum[ch];
            if (check.empty()) {
                check.push(num);
                continue;
            }
            if (num < 0) {
                if (num + check.top() == 0) check.pop();
                else return false;
            }
            else check.push(num);
        }
        return check.empty();
    }
};
// @lc code=end


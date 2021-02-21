/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
private:
    bool isNumber(string s) {
        for (char c: s) {
            if (c >= '0' and c <= '9') continue;
            if (s.size() > 1) continue;
            return false;
        }
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const auto& t: tokens) {
            if (isNumber(t)) {
                s.push(stoi(t));
                continue;
            }
            int num1, num2, tmp;
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();
            switch(t[0]) {
                case '+':
                    tmp = num1 + num2;
                    break;
                case '-':
                    tmp = num1 - num2;
                    break;
                case '*':
                    tmp = num1 * num2;
                    break;
                case '/':
                    tmp = num1 / num2;
                    break;
                default:
                    throw "Invalid input!";
            }
            s.push(tmp);
        }
        return s.top();
    }
};
// @lc code=end


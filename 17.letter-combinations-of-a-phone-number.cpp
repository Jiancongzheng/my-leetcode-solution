/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution1 {
private:
    map<char, string> buttons_{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        queue<string> string_queue;
        int len = digits.length();
        string_queue.push("");
        for (char& dig: digits) {
            int queue_len =  string_queue.size();
            while (queue_len > 0) {
                string tmp_string = string_queue.front();
                string_queue.pop();
                for (char ch: buttons_[dig]) {
                    tmp_string.push_back(ch);
                    if (tmp_string.size() == len) res.emplace_back(tmp_string);
                    else string_queue.push(tmp_string);
                    tmp_string.pop_back();
                }
                --queue_len;
            }
        }
        return res;
    }
};

class Solution {
private:
    map<char, string> buttons_{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    void dfs(const string& digits, int&& i, string& str, vector<string>& ans) {
        if (str.length() == digits.length()) {
            ans.emplace_back(str);
            return;
        }
        string candidates = buttons_[digits[i]];
        for (char& ch: candidates) {
            str.push_back(ch);
            dfs(digits, i + 1, str, ans);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        string str;
        dfs(digits, 0, str, ans);
        return ans;
    }
};
// @lc code=end


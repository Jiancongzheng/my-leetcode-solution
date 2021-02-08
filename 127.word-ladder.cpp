/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto s = unordered_set<string>(wordList.begin(), wordList.end());
        if (s.count(endWord) == 0) return 0;
        unordered_map<string, int> m;
        queue<string> q;
        q.push(beginWord);
        m[beginWord] = 1;
        while (!q.empty()) {
            string str = q.front();
            int currItr = m[str];
            q.pop();
            for (auto& ch: str) {
                char org = ch;
                for (char c = 'a'; c <= 'z'; ++c) {
                    ch = c;
                    if (s.count(str) != 0 and m.find(str) == m.end()) {
                        q.push(str);
                        m[str] = currItr + 1;
                        if (str == endWord) return m[str];
                    }
                }
                ch = org;
            }
        }
        return 0;
    }
};
// @lc code=end


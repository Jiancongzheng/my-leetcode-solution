/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, int> m;
        for (auto& str: strs) {
            vector<int> l(26, 0);
            for (char& ch: str) {
                ++l[ch - 'a'];
            }
            if (m.find(l) == m.end()) {
                m[l] = ans.size();
                ans.emplace_back(vector<string>());
            }
            ans[m[l]].emplace_back(str);
        }
        return ans;
    }
};
// @lc code=end


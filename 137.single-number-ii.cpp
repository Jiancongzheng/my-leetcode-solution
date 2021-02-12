/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& n: nums) {
            auto itr = m.find(n);
            if (itr == m.end() or itr->second == 1) ++m[n];
            else m.erase(itr);
        }
        return m.begin()->first;
    }
};
// @lc code=end


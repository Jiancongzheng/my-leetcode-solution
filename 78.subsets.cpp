/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>{});
        for (int& num: nums) {
            int len = ans.size();
            for (int i = 0; i < len; ++i) {
                auto tmp = ans[i];
                tmp.emplace_back(num);
                ans.emplace_back(tmp);
            }
        }
        return ans;
    }
};
// @lc code=end


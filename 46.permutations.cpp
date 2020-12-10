/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans{{}};
        for (int num : nums) {
            for (int i = ans.size(); i > 0; --i) {
                vector<int> vec = ans.front();
                ans.erase(ans.begin());
                for (int pos = 0; pos <= vec.size(); ++pos) {
                    vector<int> copy = vec;
                    copy.insert(copy.begin() + pos, num);
                    ans.emplace_back(copy);
                }
            }
        }
        return ans;
    }
};
// @lc code=end


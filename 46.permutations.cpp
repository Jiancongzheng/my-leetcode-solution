/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        queue<vector<int>> queue_list;
        queue_list.push(vector<int>());

        for (int i = 0; i < nums.size(); ++i) {
            int len = queue_list.size();
            for(int j = 0; j < len; ++j) {
                auto tmp = queue_list.front();
                for (int k = 0; k < tmp.size(); ++k) {
                    auto cand = tmp;
                    auto pos = cand.begin() + k;
                    cand.insert(pos, nums[i]);
                    queue_list.push(cand);
                }
                tmp.emplace_back(nums[i]);
                queue_list.push(tmp);
                queue_list.pop();
            }
        }
        while (!queue_list.empty()) {
            ans.emplace_back(queue_list.front());
            queue_list.pop();
        }
        return ans;
    }
};
// @lc code=end


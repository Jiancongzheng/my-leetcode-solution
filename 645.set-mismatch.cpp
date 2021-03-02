/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        vector<int> check(len, 0);
        for (int& n : nums) {
            int& curr = check[n - 1];
            ++curr;
            if (curr == 2) ans.emplace_back(n);
        }
        
        for (int i = 0; i < len; ++i) {
            int& c = check[i];
            if (c == 0) {
                ans.emplace_back(i + 1);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candi1 = 0, candi2 = 1;
        int cnt1 = 0, cnt2 = 0;
        for (const int& n : nums) {
            if (n == candi1) ++cnt1;
            else if (n == candi2) ++cnt2;
            else if (cnt1 == 0) {
                cnt1 = 1;
                candi1 = n;
            }
            else if (cnt2 == 0) {
                cnt2 = 1;
                candi2 = n;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (const int& n : nums) {
            if (n == candi1) ++cnt1;
            if (n == candi2) ++cnt2;
        }

        vector<int> ans;
        if (cnt1 > nums.size() / 3) ans.emplace_back(candi1);
        if (cnt2 > nums.size() / 3) ans.emplace_back(candi2);
        return ans;
    }
};
// @lc code=end


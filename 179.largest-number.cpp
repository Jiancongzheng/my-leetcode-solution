/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int& a, int& b) {
        string str1 = to_string(a);
        string str2 = to_string(b);
        return (str1 + str2) > (str2 + str1);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        int i = 0;
        while (i < nums.size() and nums[i] == 0) ++i;
        if (i == nums.size()) return "0";
        while (i < nums.size()) {
            int& n = nums[i];
            ans += to_string(n);
            ++i;
        }
        return ans;
    }
};
// @lc code=end


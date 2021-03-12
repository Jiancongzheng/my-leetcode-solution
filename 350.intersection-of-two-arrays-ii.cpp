/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int cnt1 = 1;
        int cnt2 = 1;
        int i1 = 0;
        int i2 = 0;
        vector<int> ans;
        while (i1 < nums1.size() and i2 < nums2.size()) {
            if (nums1[i1] == nums2[i2]) {
                while (i1 + 1 < nums1.size() and nums1[i1] == nums1[i1 + 1]) {
                    cnt1++;
                    i1++;
                }

                while (i2 + 1 < nums2.size() and nums2[i2] == nums2[i2 + 1]) {
                    cnt2++;
                    i2++;
                }

                int cnt = min(cnt1, cnt2);
                cnt1 = 1;
                cnt2 = 1;
                for (int i = 0; i < cnt; ++i) {
                    ans.emplace_back(nums1[i1]);
                }
                ++i1;
                ++i2;
            }
            else if (nums1[i1] < nums2[i2]) ++i1;
            else ++i2;
        }
        return ans;
    }
};
// @lc code=end


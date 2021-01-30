/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int len = m + n;
        int j = 0;
        int i = 0;
        while(i < m and j < n) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                ++j;
            }
            ++i;
        }
        int tmpn = j;
        for (i = m; i < len and j < n; ++i, ++j) {
            nums1[i] = nums2[j];
        }
        merge(nums1, i, nums2, tmpn);
    }
};
// @lc code=end


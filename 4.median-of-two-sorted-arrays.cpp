/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<float> nums;
        int i = 0, j = 0;
        int len = nums1.size() + nums2.size();
        int idx1 = len / 2;
        int idx2 = len / 2 + len % 2 - 1;
        while (i < nums1.size() or j < nums2.size())
        {
            int num1 = i < nums1.size() ? nums1[i] : INT_MAX;
            int num2 = j < nums2.size() ? nums2[j] : INT_MAX;
            if (num1 < num2) {
                nums.emplace_back(num1);
                ++i;
            }
            else {
                nums.emplace_back(num2);
                ++j;
            }
            if (nums.size() > idx2 + 1) break;
        }
        return (nums[idx1] + nums[idx2]) / 2;
    }
};
// @lc code=end

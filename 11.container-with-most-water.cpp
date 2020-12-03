/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int j = height.size() - 1;
        int i = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            int a = h * (j - i);
            maxA = max(a, maxA);
            if (height[i] < height[j]) ++i;
            else --j;
        }
        return maxA;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int ans;
        int l = 0; 
        int r = x;
        while (l < r - 1) {
            long m = (l + r) / 2;
            if (m * m <= x) l = m;
            else r = m - 1;
        }
        if (r * r <= x) return r;
        return l;
    }
};
// @lc code=end


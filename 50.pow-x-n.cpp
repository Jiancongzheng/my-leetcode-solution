/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        while (n != 0) {
            if (n > 0 and n % 2 ==  1) ans *= x;
            if (n < 0 and n % 2 == -1) ans /= x;
            x *= x;
            n /= 2;
        }
        return ans;
    }
};
// @lc code=end


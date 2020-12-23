/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution1 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

// Lagrange's four-square theorem
// 数学方法也太顶了吧
class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int i = 0; i*i <= n; i++) {
            int j = sqrt(n - i * i);
            if (j * j + i * i == n) {
                if (j != 0 and i != 0) {
                    return 2;
                }
                return 1;
            }
        }
        return 3;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        int cnt = 0;
        vector<bool> v(n, true);
        v[1] = false;
        for (int i = 2; i < n; ++i) {
            if (v[i] == true) cnt++;
            for (int t = 2; t * i < n; ++t) {
                v[t * i] = false;
            }
        }
        return cnt;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
private:
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int cnt = 0;
        while (n > 2) {
            --n;
            if (isPrime(n)) {
                ++cnt;
            }
        }
        return cnt;
    }
};
// @lc code=end


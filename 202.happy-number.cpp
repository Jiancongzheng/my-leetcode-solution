/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while (n != 1) {
            int tmp = 0;
            while (n != 0) {
                tmp += pow(n % 10, 2);
                n /= 10;
            }
            n = tmp;
            if (s.count(n) != 0) return false;
            s.insert(n);
        }
        return true;
    }
};
// @lc code=end


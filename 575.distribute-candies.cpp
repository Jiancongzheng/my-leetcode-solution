/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        int cntType = s.size();
        int cntCndy = candyType.size() / 2;
        return min(cntType, cntCndy);
    }
};
// @lc code=end


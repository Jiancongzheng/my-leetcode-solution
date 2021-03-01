/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

// @lc code=start
class Solution1 {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        int cntType = s.size();
        int cntCndy = candyType.size() / 2;
        return min(cntType, cntCndy);
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(), candyType.end());
        int pre = candyType.front();
        int cnt = 1;
        for (int& c : candyType) {
            if (c == pre) continue;
            pre = c;
            ++cnt;
        }
        if (cnt < candyType.size() / 2) return cnt;
        return candyType.size() / 2;
    }
};
// @lc code=end


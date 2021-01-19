/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        while (n > 1)
        {
            int cnt = 1;
            string tmp;
            for (int i = 0; i < ans.length(); ++i)
            {
                if (i + 1 == ans.length() or ans[i] != ans[i + 1])
                {
                    tmp.push_back('0' + cnt);
                    tmp.push_back(ans[i]);
                    cnt = 1;
                    continue;
                }
                cnt++;
            }
            ans = tmp;
            --n;
        }
        return ans;
    }
};
// @lc code=end

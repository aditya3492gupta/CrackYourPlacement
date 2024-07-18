/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int res = 0;
        for (int i = 0; i < k; i++)
            res += cardPoints[i];
        int cnt = res;
        for (int i = k - 1; i >= 0; i--)
        {
            cnt -= cardPoints[i];
            cnt += cardPoints[cardPoints.size() - k + i];
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end

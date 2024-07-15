/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    int check(vector<int> &p, int b, int n, vector<vector<int>> dp)
    {
        if (n == p.size())
            return 0;
        if (dp[n][b] != -1)
            return dp[n][b];
        if (b)
            return dp[n][b] = max(-p[n] + check(p, 0, n + 1, dp), 0 + check(p, 1, n + 1, dp));
        else
            return dp[n][b] = max(p[n] + check(p, 1, n + 1, dp), 0 + check(p, 0, n + 1, dp));
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j)
                    dp[i][j] = max(0 + dp[i + 1][1], prices[i] + dp[i + 1][0]);
                else
                    dp[i][j] = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

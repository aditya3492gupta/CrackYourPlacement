/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (auto s : strs)
        {

            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;

            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
        }

        return dp[m][n];
    }
};
// @lc code=end

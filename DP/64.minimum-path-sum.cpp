/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
public:
    int solve(vector<vector<int>> &g, int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 and j == 0)
            return g[0][0];
        if (i < 0 or j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = INT_MAX;
        int left = INT_MAX;

        if (i > 0)
        {
            up = g[i][j] + solve(g, i - 1, j, dp);
        }
        if (j > 0)
        {
            left = g[i][j] + solve(g, i, j - 1, dp);
        }

        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, n - 1, m - 1, dp);
    }
};
// @lc code=end

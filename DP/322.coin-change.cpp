/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amt + 1, amt + 1);
        dp[0] = 0;
        for (int i = 1; i <= amt; i++)
            for (int j = 0; j < n; j++)
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        if (dp[amt] == amt + 1)
            return -1;
        return dp[amt];
    }
};
// @lc code=end

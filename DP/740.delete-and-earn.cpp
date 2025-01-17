/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution
{
public:
    int val[10003];
    int dp[10003];
    int deleteAndEarn(vector<int> &nums)
    {

        int N = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        for (int i : nums)
            val[i] += i;

        dp[1] = val[1];
        for (int i = 2; i < mx + 1; ++i)
            dp[i] = max(dp[i - 1], dp[i - 2] + val[i]);

        return dp[mx];
    }
};
// @lc code=end

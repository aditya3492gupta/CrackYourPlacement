/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        int m = B.size();
        vector<int> dp(n, vector<int>(m));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (A[i] == B[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
            }
        }
        int maxm = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                maxm = max(maxm, dp[i][j]);
            }
        }

        return maxm;
    }
};
// @lc code=end

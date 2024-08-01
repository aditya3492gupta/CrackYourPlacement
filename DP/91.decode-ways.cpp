/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution
{
public:
    int solve(int index, int n, string str, vector<int> &dp)
    {
        if (index >= n)
            return 1;
        if (dp[index] != -1)
            return dp[index];
        string temp = "";
        int ans = 0;
        for (int i = index; i < n; i++)
        {
            temp += str[i];
            int a = stoi(temp);
            if (a >= 1 and a <= 26)
            {
                ans += solve(i + 1, n, str, dp);
            }
            else
            {
                break;
            }
        }
        return dp[index] = ans;
    }
    int numDecodings(string str)
    {
        int n = str.length();
        vector<int> dp(n, -1);
        int ans = solve(0, n, str, dp);
        return ans;
    }
};
// @lc code=end

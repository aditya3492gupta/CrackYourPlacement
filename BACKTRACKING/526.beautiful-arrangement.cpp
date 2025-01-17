/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution
{
public:
    unordered_map<int, vector<int>> m;
    int countArrangement(int n)
    {
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i % j == 0 || j % i == 0)
                    m[i].push_back(j);
        return fun(v, n);
    }
    int fun(vector<int> &vis, int n)
    {
        if (n <= 0)
            return 1;
        int t = 0;
        for (auto x : m[n])
            if (vis[x] == 0)
            {
                vis[x] = 1;
                t += fun(vis, n - 1);
                vis[x] = 0;
            }
        return t;
    }
};
// @lc code=end

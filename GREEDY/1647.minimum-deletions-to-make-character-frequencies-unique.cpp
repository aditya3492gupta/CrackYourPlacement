/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

// @lc code=start
class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> f(26, 0);
        for (auto i : s)
        {
            f[i - 'a']++;
        }
        sort(f.begin(), f.end());
        int ans = 0;
        for (int i = 24; i >= 0; i--)
        {
            if (f[i] == 0)
                break;
            if (f[i] >= f[i + 1])
            {
                int x = f[i];
                f[i] = max(0, f[i + 1] - 1);
                ans += x - f[i];
            }
        }
        return ans;
    }
};
// @lc code=end

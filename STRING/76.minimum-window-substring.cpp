/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> mp(128);
        int left = 0, right = 0, ans = INT_MAX, si = 0;
        for (auto i : t)
            mp[i]++;
        int n = s.size();
        int m = t.size();
        while (right < n)
        {
            if (mp[s[right++]]-- > 0)
                m--;
            while (m == 0)
            {
                if (right - left < ans)
                {
                    si = left;
                    ans = right - left;
                }
                if (mp[s[left++]]++ == 0)
                    m++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(si, ans);
    }
};
// @lc code=end

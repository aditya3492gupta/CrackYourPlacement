/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> a, b;
        int n = s.size();
        int m = t.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '#')
            {
                if (!a.empty())
                    a.pop();
            }
            else
                a.push(s[i]);
        }
        for (int i = 0; i < m; i++)
        {
            if (t[i] == '#')
            {
                if (!b.empty())
                    b.pop();
            }
            else
                b.push(t[i]);
        }

        while (!a.empty() and !b.empty())
        {
            if (a.top() != b.top())
                return false;
            a.pop();
            b.pop();
        }
        return a.empty() and b.empty();
    }
};
// @lc code=end

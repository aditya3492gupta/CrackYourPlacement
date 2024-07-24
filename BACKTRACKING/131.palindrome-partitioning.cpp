/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    bool pal(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void gen(vector<vector<string>> &ans, vector<string> &d, string s, int i)
    {
        if (i == s.size())
        {
            ans.push_back(d);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            if (pal(s, i, j))
            {
                d.push_back(s.substr(i, j - i + 1));
                gen(ans, d, s, j + 1);
                d.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> d;
        gen(ans, d, s, 0);
        return ans;
    }
};
// @lc code=end

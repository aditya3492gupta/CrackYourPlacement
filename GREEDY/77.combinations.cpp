/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
public:
    void check(int n, int k, vector<vector<int>> &ans, vector<int> &temp, int x)
    {
        if (temp.size() == k)
        {
            ans.push_back(temp);
        }
        for (int i = x; i < n + 1; i++)
        {
            temp.push_back(i);
            check(n, k, ans, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        check(n, k, ans, temp, 1);
        return ans;
    }
};
// @lc code=end

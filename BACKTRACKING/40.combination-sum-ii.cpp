/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    void gen(vector<vector<int>> &ans, vector<int> temp, int i, vector<int> a, long long k)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int j = i; j < a.size(); j++)
        {
            if (j > i and a[j] == a[j - 1])
                continue;
            if (a[j] > k)
                break;
            temp.push_back(a[j]);
            gen(ans, temp, j + 1, a, k - a[j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &a, int k)
    {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        gen(ans, temp, i, a, k);
        return ans;
    }
};
// @lc code=end

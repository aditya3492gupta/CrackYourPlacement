/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    void gen(set<vector<int>> &a, vector<int> temp, vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            sort(temp.begin(), temp.end());
            a.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        gen(a, temp, nums, i + 1);
        temp.pop_back();
        gen(a, temp, nums, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> a;
        gen(a, temp, nums, 0);
        sort(ans.begin(), ans.end());
        for (auto it : a)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
// @lc code=end

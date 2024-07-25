/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    void util(vector<int> &nums, int i, vector<int> &currSubset, vector<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[i]);
        util(nums, i + 1, currSubset, ans);
        currSubset.pop_back();
        util(nums, i + 1, currSubset, ans);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> currSubset;
        int i = 0;
        util(nums, i, currSubset, ans);
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
                result.push_back(index + 1);
            else
                nums[index] = -nums[index];
        }
        return result;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution
{
public:
    bool check(vector<int> &nums, int k, int mid, int n)
    {
        int sum = 0;
        int maxi = INT_MIN;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + nums[i] <= mid)
                sum += nums[i];
            else
            {
                sum = nums[i];
                cnt++;
            }
        }
        return cnt > k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = *max_element(nums.begin(), nums.end());
        int j = accumulate(nums.begin(), nums.end(), 0);
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (check(nums, k, mid, n))
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
};
// @lc code=end

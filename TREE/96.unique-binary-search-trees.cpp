/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> result(n + 1);
        result[1] = result[0] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                result[i] += result[j] * result[i - j - 1];
        return result[n];
    }
};
// @lc code=end

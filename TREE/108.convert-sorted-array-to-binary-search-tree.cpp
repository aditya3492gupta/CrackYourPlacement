/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *solve(vector<int> &a, int l, int r)
    {
        if (l > r)
            return nullptr;
        int m = l + (r - l) / 2;
        TreeNode *root = new TreeNode(a[m]);
        root->left = solve(a, l, m - 1);
        root->right = solve(a, m + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

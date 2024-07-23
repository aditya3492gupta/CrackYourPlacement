/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    void getLeftSum(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        if (root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        getLeftSum(root->left, sum);
        getLeftSum(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        getLeftSum(root, sum);
        return sum;
    }
};
// @lc code=end

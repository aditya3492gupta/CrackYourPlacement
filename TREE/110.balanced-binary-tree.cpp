/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int h(TreeNode *r)
    {
        if (r == nullptr)
            return 0;
        int a = h(r->left);
        int b = h(r->right);
        return max(a + 1, b + 1);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int a = h(root->left);
        int b = h(root->right);
        if (abs(a - b) <= 1 and isBalanced(root->left) and isBalanced(root->right))
            return true;
        return false;
    }
};
// @lc code=end

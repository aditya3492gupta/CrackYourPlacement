/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool check(TreeNode *root, long long l, long long r)
    {
        if (root == nullptr)
            return true;
        if (root->val < r and root->val > l)
            return check(root->left, l, root->val) and check(root->right, root->val, r);
        else
            return false;
    }
    bool isValidBST(TreeNode *root)
    {
        return check(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

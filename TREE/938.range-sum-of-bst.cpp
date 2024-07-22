/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    int rangeSumBST(TreeNode *r, int l, int h)
    {
        if (r == nullptr)
            return 0;
        if (r->val <= h and r->val >= l)
            return r->val + rangeSumBST(r->left, l, h) + rangeSumBST(r->right, l, h);
        if (r->val < l)
            return rangeSumBST(r->right, l, h);
        return rangeSumBST(r->left, l, h);
    }
};
// @lc code=end

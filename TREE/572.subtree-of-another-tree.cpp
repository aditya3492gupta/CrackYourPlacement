/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSame(TreeNode *r, TreeNode *s)
    {
        if (!r or !s)
            return r == nullptr and s == nullptr;
        else if (r->val == s->val)
            return isSame(r->left, s->left) and isSame(r->right, s->right);
        else
            return false;
    }
    bool isSubtree(TreeNode *r, TreeNode *s)
    {
        if (!r)
            return false;
        else if (isSame(r, s))
            return true;
        else
            return isSubtree(r->left, s) or isSubtree(r->right, s);
    }
};
// @lc code=end

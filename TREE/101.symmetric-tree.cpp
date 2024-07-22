/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        queue<TreeNode *> nodeQue;
        nodeQue.push(root->left);
        nodeQue.push(root->right);
        while (!nodeQue.empty())
        {
            TreeNode *temp1 = nodeQue.front();
            nodeQue.pop();
            TreeNode *temp2 = nodeQue.front();
            nodeQue.pop();

            if (temp1 == NULL && temp2 == NULL)
                continue;
            if (temp1 == NULL || temp2 == NULL)
                return false;
            if (temp1->val != temp2->val)
                return false;
            nodeQue.push(temp1->left);
            nodeQue.push(temp2->right);
            nodeQue.push(temp1->right);
            nodeQue.push(temp2->left);
        }
        return true;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    void inorder(TreeNode *root, vector<int> &a)
    {
        if (root == nullptr)
            return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> num;
        inorder(root, num);
        int n = num.size();
        int d = abs(num[0] - num[1]);
        for (int i = 1; i < n - 1; i++)
        {
            d = min(d, abs(num[i] - num[i + 1]));
        }
        return d;
    }
};
// @lc code=end

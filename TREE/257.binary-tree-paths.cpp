/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void check(vector<string> &ans, string s, TreeNode *root)
    {
        if (root == nullptr)
            return;
        s += to_string(root->val);
        if (!root->left and !root->right)
            ans.push_back(s);
        check(ans, s + "->", root->left);
        check(ans, s + "->", root->right);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string s = "";
        check(ans, s, root);
        return ans;
    }
};
// @lc code=end

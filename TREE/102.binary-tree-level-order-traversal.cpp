/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    void dfs(TreeNode *node, vector<vector<int>> &res, int level)
    {
        if (!node)
            return;
        if (level == res.size())
            res.push_back({});
        res[level].push_back(node->val);
        dfs(node->left, res, level + 1);
        dfs(node->right, res, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        dfs(root, ans, 0);
        return ans;
    }
};
// @lc code=end

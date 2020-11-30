/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or root == p or root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if (left != q and left != p and left != nullptr) return left;
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (right == nullptr) return left;
        if (left == nullptr) return right;
        return root;
    }
};
// @lc code=end


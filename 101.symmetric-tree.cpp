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
class Solution {
private:
    bool validate(TreeNode* l, TreeNode* r) {
        if (l == nullptr and r == nullptr) return true;
        if (l == nullptr or r == nullptr) return false;
        if (l->val != r->val) return false;
        return validate(l->left, r->right) and validate(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return validate(root->left, root->right);
    }
};
// @lc code=end


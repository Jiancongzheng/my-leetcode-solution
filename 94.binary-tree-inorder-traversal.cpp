/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
class SolutionRecursion {
private:
    void helper(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        helper(root->left, ans);
        ans.emplace_back(root->val);
        helper(root->right, ans);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> nodeStack;
        TreeNode* node = root;
        while (node != nullptr or !nodeStack.empty()) {
            while (node != nullptr) {
                nodeStack.push(node);
                node = node->left;
            }
            node = nodeStack.top();
            nodeStack.pop();
            ans.emplace_back(node->val);
            node = node->right;
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
        ans.emplace_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node = root;
        stack<TreeNode*> nodeStack;
        while(node != nullptr or !nodeStack.empty()) {
            while (node != nullptr) {
                ans.emplace_back(node->val);
                nodeStack.push(node->right);
                node = node->left;
            }
            node = nodeStack.top();
            nodeStack.pop();
        }
        return ans;
    }
};
// @lc code=end


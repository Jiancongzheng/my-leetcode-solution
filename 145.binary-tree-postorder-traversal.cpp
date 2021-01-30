/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
        helper(root->right, ans);
        ans.emplace_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        TreeNode* node = root;
        stack<TreeNode*> nodeStack;
        nodeStack.push(node);
        while (!nodeStack.empty()) {
            node = nodeStack.top();
            ans.emplace_back(node->val);
            nodeStack.pop();
            if (node->left != nullptr) nodeStack.push(node->left);
            if (node->right != nullptr) nodeStack.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end


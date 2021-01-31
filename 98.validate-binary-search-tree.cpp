/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

// Solution 1: 递归
// Solution 2: 中序遍历

class SolutionRecursion {
private:
    bool helper(TreeNode* root, long maxVal, long minVal) {
        if (root == nullptr) return true;
        if (root->val >= maxVal or root->val <= minVal) return false;
        return helper(root->left, root->val, minVal) and helper(root->right, maxVal, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX, LONG_MIN);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* n = root;
        long prev = LONG_MIN;
        while (n != nullptr or !stk.empty()) {
            while (n != nullptr) {
                stk.push(n);
                n = n->left;
            }
            n = stk.top();
            if (n->val <= prev) return false;
            prev = n->val;
            stk.pop();
            n = n->right;
        }
        return true;
    }
};
// @lc code=end


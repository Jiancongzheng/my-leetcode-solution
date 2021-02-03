/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* spawn(vector<int>& preorder, vector<int>& inorder, int begPre, int endPre, int begIn, int endIn) {
        if (begPre > endPre) return nullptr;
        auto* n = new TreeNode(preorder[begPre]);
        if (begPre == endPre) return n;
        int i;
        for (i = begIn; i <= endIn; ++i) {
            if (inorder[i] == preorder[begPre]) break;
        }
        n->left = spawn(preorder, inorder, begPre + 1, begPre + i - begIn, begIn, i - 1);
        n->right = spawn(preorder, inorder, begPre + i - begIn + 1, endPre, i + 1, endIn);
        return n;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return spawn(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end


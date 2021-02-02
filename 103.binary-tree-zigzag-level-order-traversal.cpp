/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        unique_ptr<stack<TreeNode*>> s;
        s.reset(new stack<TreeNode*>);
        s->push(root);
        int turn = 1;
        while(!s->empty()) {
            unique_ptr<stack<TreeNode*>> tmp_s;
            tmp_s.reset(new stack<TreeNode*>);
            vector<int> r;
            while (!s->empty()) {
                auto* n = s->top();
                s->pop();
                r.emplace_back(n->val);
                if (turn % 2 == 1) {
                    if (n->left != nullptr) tmp_s->push(n->left);
                    if (n->right != nullptr) tmp_s->push(n->right);
                }
                else {
                    if (n->right) tmp_s->push(n->right);
                    if (n->left) tmp_s->push(n->left);
                }
            }
            ans.emplace_back(r);
            ++turn;
            *s = *tmp_s;
        }
        return ans;
    }
};
// @lc code=end


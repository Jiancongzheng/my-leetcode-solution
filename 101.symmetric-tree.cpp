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
public:
    bool isSymmetric(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<TreeNode*> v;
            while(len > 0) {
                auto* n = q.front();
                q.pop();
                --len;
                if (n == nullptr) continue;
                v.emplace_back(n->left);
                v.emplace_back(n->right);
                q.push(n->left);
                q.push(n->right);
            }
            for (int i = 0, j = v.size() - 1; i < j; ++i, --j) {
                if (v[i] == nullptr and v[j] == nullptr) continue;
                if (v[i] == nullptr or v[j] == nullptr) return false;
                if (v[i]->val != v[j]->val) return false;
            }
            
        }
        return true;
    }
};
// @lc code=end


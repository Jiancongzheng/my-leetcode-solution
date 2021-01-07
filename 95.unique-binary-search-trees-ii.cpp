/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> helper(int head, int tail) {
        if (head > tail) {
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> res_list;
    
        for (int i = head; i <= tail; ++i) {
            auto left_list = helper(head, i - 1);
            auto right_list = helper(i + 1, tail);
            for (auto& left: left_list) {
                for (auto& right: right_list) {
                    auto new_tree = new TreeNode(i);
                    new_tree->left = left;
                    new_tree->right = right;
                    res_list.emplace_back(new_tree);
                }
            }
        }
        return res_list;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>{};

        return helper(1, n);
    }
};
// @lc code=end


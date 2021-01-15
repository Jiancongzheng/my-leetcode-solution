/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0) return nullptr;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto* h: lists) {
            while (h != nullptr) {
                q.push(h->val);
                h = h->next;
            }
        }

        auto* res = new ListNode(0);
        auto* r = res;
        while (!q.empty()) {
            r->next = new ListNode(q.top());
            q.pop();
            r = r->next;
        }
        return res->next;
    }
};
// @lc code=end


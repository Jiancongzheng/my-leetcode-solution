/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        auto* h1 = head;
        auto* h2 = head->next;
        while (h2 != nullptr and h2->next != nullptr) {
            if (h1 == h2) return true;
            h1 = h1->next;
            h2 = h2->next->next;
        }
        return false;
    }
};
// @lc code=end


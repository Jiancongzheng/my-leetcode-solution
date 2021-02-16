/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr or head->next == nullptr) return nullptr;
        auto *h1 = head, *h2 = head;
        do {
            if (h2->next == nullptr) return nullptr;
            if (h2->next->next == nullptr) return nullptr;
            h2 = h2->next->next;
            h1 = h1->next;
        } while (h2 != h1);
        h1 = head;
        while (h1 != h2) {
            h1 = h1->next;
            h2 = h2->next;
        }
        return h1;
    }
};
// @lc code=end


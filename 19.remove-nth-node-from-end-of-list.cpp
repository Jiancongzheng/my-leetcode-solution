/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;
        ListNode* t = head;
        while (n > 0) {
            --n;
            t = t->next;
        }
        if (t == nullptr) return head->next;
        ListNode* h = head;
        while (t->next != nullptr) {
            t = t->next;
            h = h->next;
        }
        h->next = h->next->next;
        return head;
    }
};
// @lc code=end


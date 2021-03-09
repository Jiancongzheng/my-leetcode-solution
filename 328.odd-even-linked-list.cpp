/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr or head->next == nullptr or head->next->next == nullptr) return head;
        ListNode* even = new ListNode(0);
        ListNode* e = even;
        ListNode* h = head;
        while (h->next != nullptr and h->next->next != nullptr) {
            e->next = h->next;
            h->next = h->next->next;
            h = h->next;
            e = e->next;
            e->next = nullptr;
        }
        if (h->next != nullptr) {
            e->next = h->next;
        } 
        h->next = even->next;
        return head;
    }
};
// @lc code=end


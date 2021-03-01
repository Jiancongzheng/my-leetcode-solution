/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        auto* h = head->next;
        auto* res = head;
        res->next = nullptr;
        while (h != nullptr) {
            auto* tmp = h->next;
            h->next = res;
            res = h;
            h = tmp;
        }
        return res;
    }
};
// @lc code=end


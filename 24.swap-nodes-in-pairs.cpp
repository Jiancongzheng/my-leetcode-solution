/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        auto* h = head;
        while (h != nullptr and h->next != nullptr) {
            swap(h->val, h->next->val);
            h = h->next->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;
        auto* h = head->next;
        head->next = h->next;
        h->next = head;
        head = h;
        h = head->next;

        while (h->next != nullptr and h->next->next != nullptr) {
            auto *tmp1 = h->next;
            auto *tmp2 = h->next->next;
            h->next = tmp2;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1; 
            h = h->next->next;
        }
        return head;
    }
};
// @lc code=end


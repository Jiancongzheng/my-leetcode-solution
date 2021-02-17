/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;
        int pivot;
        bool isSorted = false;
        while (!isSorted)
        {
            isSorted = true;
            ListNode *p = head;
            while (p->next) {
                if (p->val > p->next->val) {
                    isSorted = false;
                    break;
                }
                p = p->next;
            }
            if (isSorted) break;
            
            bool isChanged = false;
            pivot = head->val;
            p = head;
            while (p and p->next) {
                if (p->next->val < pivot) {
                    isChanged = true;
                    ListNode *tmp_p = p->next;
                    p->next = p->next->next;
                    tmp_p->next = head;
                    head = tmp_p;
                }
                else {
                    p = p->next;
                }
            }
            if (isChanged == false) {
                head->next = sortList(head->next);
            }
        }
        return head;
    }
};
// @lc code=end


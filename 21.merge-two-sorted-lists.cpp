/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto* res = new ListNode(0);
        auto* r = res;
        while (l1 != nullptr and l2 != nullptr) {
            if (l1->val <= l2->val) {
                r->next = l1;
                l1 = l1->next;
            }
            else {
                r->next = l2;
                l2 = l2->next;
            }
            r = r->next;
        }
        r->next = l1 == nullptr ? l2 : l1;
        return res->next;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* res = new ListNode(0);
        ListNode* r = res;
        int carry = 0;
        while (node1 != nullptr or node2 != nullptr or carry == 1) {
            int num1 = 0;
            int num2 = 0;
            if (node1 != nullptr) {
                num1 = node1->val;
                node1 = node1->next;
            }
            if (node2 != nullptr) {
                num2 = node2->val;
                node2 = node2->next;
            }
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            r->next = new ListNode(sum);
            r = r->next;
        }
        return res->next;
    }
};
// @lc code=end


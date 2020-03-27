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
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        ListNode* result = new ListNode(0);
        ListNode* r = result;
        int complement = 0;
        while (h1 or h2) {
            int sum;
            sum = complement + (h1 ? h1->val : 0) + (h2 ? h2->val : 0);
            r->next = (sum >= 10) ? new ListNode(sum - 10) : new ListNode(sum);
            complement = (sum >= 10) ? 1 : 0;
            r = r->next;
            h1 = h1 ? h1->next : nullptr;
            h2 = h2 ? h2->next : nullptr;
        }
        if (complement) {
            r->next = new ListNode(1);
        }
        return result->next;
    }
};
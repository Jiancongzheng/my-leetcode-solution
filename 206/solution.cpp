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
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* p, * s;
        p = new ListNode(head->val);
        s = head->next;
        while (s)
        {
            ListNode* tmp = new ListNode(s->val);
            tmp->next = p;
            p = tmp;
            s = s->next;
        }
        return p;
    }
};

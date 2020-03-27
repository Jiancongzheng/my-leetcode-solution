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
    ListNode* nthFrom(ListNode* p, int n) {
        for (int i = 0; i < n; i++)
        {
            p = p->next;
        }
        return p;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode* p, * s;
        p = head;
        s = nthFrom(p, n);
        if (!s)
        {
            return head->next;
        }
        while (s->next)
        {
            p = p->next;
            s = s->next;
        }
        ListNode* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        return head;
    }
};
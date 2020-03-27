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
    ListNode* quickSort(ListNode* head, ListNode* tail) {
        ListNode* p, * l, * s;
        p = head;
        if (p == tail or p->next == tail) return p;

        s = p;
        l = p->next;
        while (l != tail)
        {
            if (l->val < s->val)
            {
                p->next = l->next;
                l->next = head;
                head = l;
                l = p->next;
            }
            else
            {
                l = l->next;
                p = p->next;
            }
        }

        ListNode* right = quickSort(s->next, tail); //不要把pivot放入
        s->next = right;
        ListNode* left = quickSort(head, s);
        return left;
    }

    ListNode* sortList(ListNode* head) {
        return quickSort(head, NULL);;
    }
};
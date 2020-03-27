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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a, * b;
        a = headA;
        b = headB;
        if (!a or !b) return NULL;
        while (true)
        {
            if (a == b) return a;
            else if (a and b)
            {
                a = a->next;
                b = b->next;
            }
            else if (a)
            {
                b = headA;
            }
            else a = headB;
        }
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p, * s;
        p = head;
        while (p && p->next) {
            if (p->val != p->next->val) {
                p = p->next;
            }
            else {
                s = p->next;
                p->next = p->next->next;
                delete s;
            }
        }
        return head;
    }
};
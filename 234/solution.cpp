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
    bool isPalindrome(ListNode* head) {
        ListNode* p, * s;
        p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        for (int i = 0; i < len / 2; i++) {
            s = head;
            head = head->next;
            s->next = p;
            p = s;
        }
        s = (len % 2) ? head->next : head;
        while (p and s) {
            if (p->val != s->val) return false;
            p = p->next;
            s = s->next;
        }
        return true;
    }
};
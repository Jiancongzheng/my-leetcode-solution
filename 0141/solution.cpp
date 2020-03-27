/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    bool hasCycle(ListNode* head) {
        ListNode* p;
        p = head;
        int pos = 0;
        map<ListNode*, int> m;
        while (p && p->next) {
            if (m.find(p) != m.end()) return true;
            m[p] = pos;
            p = p->next;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* p1, * p2;
        if (!head || !head->next) return false;
        p1 = head;
        p2 = head->next;
        while (p2 && p2->next) {
            if (p1 == p2) return true;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return false;
    }
};
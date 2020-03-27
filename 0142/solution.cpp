/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // hash table
class Solution1 {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* p;
        int pos = -1;
        p = head;
        map<ListNode*, int> m;
        while (p) {
            if (m.find(p) != m.end()) return p;
            pos++;
            m[p] = pos;
            p = p->next;
        }
        return NULL;
    }
};


// Two pointers
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* p1, * p2;
        p1 = head;
        p2 = head;
        if (!head or !head->next) return NULL;
        while (p2 and p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) break;
        }
        if (!p2 or !p2->next) return NULL;
        p1 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
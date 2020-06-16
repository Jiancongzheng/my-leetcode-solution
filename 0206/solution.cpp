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
        ListNode* r;
        if (head == nullptr or head->next == nullptr) return head;
        r = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return r;
    }
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* r = new ListNode(0);
        ListNode* p;
        if (head == nullptr) return head;
        while (head != nullptr) {
            p = r->next;
            r->next = head;
            head = head->next;
            r->next->next = p;
            p = r->next;
        }
        return r->next;
    }
};

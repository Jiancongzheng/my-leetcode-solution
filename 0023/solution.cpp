/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *r = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            r = mergeTwoLists(r, lists[i]);
        }
        return r;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *p1, *p2, *p3, *r;
        p1 = l1;
        p2 = l2;
        if (p1->val <= p2->val) {
            r = p1;
            p1 = p1->next;
        }
        else 
        {
            r = p2;
            p2 = p2->next;
        }
        p3 = r;
        while (p1 and p2) {
            if (p1->val <= p2->val) 
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else 
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        if (p1) p3->next = p1;
        if (p2) p3->next = p2;
        return r;
    }
};

class Solution_sort {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (int i = 0; i < lists.size(); i++) {
            ListNode *p = lists[i];
            while (p) {
                v.push_back(p->val);
                p = p->next;
            }
        }
        
        sort(v.begin(), v.end());
        ListNode *r = new ListNode(0);
        ListNode *p = r;
        for (int i = 0; i < v.size(); i++) {
            p->next = new ListNode(v[i]);
            p = p->next;
        }
        return r->next;
    }
};
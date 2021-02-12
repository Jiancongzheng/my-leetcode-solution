/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        auto* h = head;
        while (h != nullptr) {
            Node* tmp = new Node(h->val);
            tmp->next = h->next;
            h->next = tmp;
            h = h->next->next;
        }

        h = head;
        while (h != nullptr) {
            if (h->random != nullptr) h->next->random = h->random->next;
            else h->next->random = nullptr;
            h = h->next->next;
        }

        auto* copy = head->next;
        h = head;
        while (h != nullptr) {
            Node* tmp = h->next;
            h->next = tmp->next;
            h = h->next;
            if (h != nullptr) tmp->next = h->next;
        }
        return copy;
    }
};
// @lc code=end


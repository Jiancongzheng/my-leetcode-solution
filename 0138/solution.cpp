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
        if (!head) {
            return nullptr;
        }
        Node *p = head;
        
        while (p != nullptr) {
            Node *tmp = new Node(p->val);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
        p = head;
        
        while (p != nullptr) {
            if(p->random != nullptr) {
                p->next->random = p->random->next;
            }
            else {
                p->next->random = nullptr;
            }
            p = p->next->next;
        }
        
        Node *copy = head->next;
        p = head;
        while (p->next->next != nullptr) {
            Node *tmp = p->next;
            p->next = p->next->next;
            tmp->next = tmp->next->next;
            p = p->next;
        }
        p->next = nullptr;
        return copy;
    }
};

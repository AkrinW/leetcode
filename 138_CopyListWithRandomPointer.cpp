#include <iostream>
#include <unordered_map>

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

int main() {
    Node *head = new Node(1);
    std::unordered_map<Node*, Node*> map;
    if (head == nullptr) {
        return 0;
    }
    Node *newhead = new Node(0);
    Node *p = head, *q = newhead;
    while (p != nullptr) {
        q->val = p->val;
        if (p->next) {
            q->next = new Node(0);
        }
        map[p] = q;
        q = q->next;
        p = p->next;
    }
    p = head;
    q = newhead;
    while (p != nullptr) {
        if (p->random == nullptr) {
            q->random = nullptr;
        } else {
            q->random = map[p->random];
        }
        p = p->next;
        q = q->next;
    }

    return 0;
}